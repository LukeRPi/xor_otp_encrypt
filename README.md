**XOR OTP ENCRYPT / DECRYPT**

This code is based on [RavuAlHemio/cpptotp](https://github.com/RavuAlHemio/cpptotp).

*DISCLAIMER!!!!*

This software comes with ABSOLUTELY NO WARRANTY and it isn’t safe to use if you really want to encrypt something, because XOR encryption isn’t strong and the OTP key is stored as a string in the compiled object code.

*How to setup*

Visit [this site](https://freeotp.github.io/qrcode.html) and generate an OTP key.

You will find a variable named key: insert your key between the quotes.

*How to build*

Compile with cmake:

mkdir build

cd build

cmake ..

make


