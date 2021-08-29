#include "libcppotp/bytes.h"
#include "libcppotp/otp.h"

#include <algorithm>

#include <iostream>

#include <cctype>
#include <cstdio>
#include <unistd.h>

#include <termios.h>

using namespace CppTotp;

std::string normalizedBase32String(const std::string & unnorm)
{
	std::string ret;

	for (char c : unnorm)
	{
		if (c == ' ' || c == '\n' || c == '-')
		{
			// skip separators
		}
		else if (std::islower(c))
		{
			// make uppercase
			char u = std::toupper(c);
			ret.push_back(u);
		}
		else
		{
			ret.push_back(c);
		}
	}

	return ret;
}

bool otp()
{
	// read the key
	std::string key;
	key = "your-otp-key";
	

	std::string normalizedKey = normalizedBase32String(key);
	Bytes::ByteString qui = Bytes::fromUnpaddedBase32(normalizedKey);
	int p = totp(qui, time(NULL), 0, 30, 6);
	int p1;
	printf("OTP: ");
	scanf("%d", &p1);
	if (p == p1)
		return true;
	else
		return false;
}
	
std::string encryptDecrypt(std::string toEncrypt) {
    char key[10] = {'A', 'B'}; 			// Any chars will work, you can add multiple if you want
    std::string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];		// encrypt or decrypt string
    
    return output;
}

void encr(std::string tenc)
{
    std::string encrypted = encryptDecrypt(tenc);
    std::cout << "Result:" << encrypted << "\n";
}

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
	printf("Text to encrypt/decrypt: ");
    std::string tenc;
    std::getline(std::cin, tenc);												// get string
	std::transform(tenc.begin(), tenc.end(), tenc.begin(), asciitolower);		// make string lowercase

	if (otp() == true)
	{
		encr(tenc);				// encrypt or decrypt tenc string
	} else
	std::cout << "!!!WRONG OTP!!!" << std::endl;
	

}