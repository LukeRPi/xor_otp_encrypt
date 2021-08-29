# XOR OTP ENCRYPT / DECRYPT

This code is based on [RavuAlHemio/cpptotp](https://github.com/RavuAlHemio/cpptotp).

## DISCLAIMER!!!!

This software comes with ABSOLUTELY NO WARRANTY and it isn’t safe to use if you really want to encrypt something, because XOR encryption isn’t strong and the OTP key is stored as a string in the compiled object code.

## How to setup

Visit [this site](https://freeotp.github.io/qrcode.html) and generate an OTP key.

In the file encrypt.cpp you will find a variable named key: insert your key between the quotes.

You can use an OTP app, such as Google Authenticator ([iOS](https://apps.apple.com/it/app/google-authenticator/id388497605) and [Android](https://play.google.com/store/apps/details?id=com.google.android.apps.authenticator2)) on your phone to validate the OTP request on your PC.

## How to build

Clone and compile with cmake:
```sh
git clone https://github.com/LukeRPi/xor_otp_encrypt.git
cd xor_otp_encrypt
mkdir build
cd build
cmake ..
make
```

