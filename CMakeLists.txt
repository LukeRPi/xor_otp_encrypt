cmake_minimum_required (VERSION 2.6)
project (CppOtp)

# activate C++11 mode
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)

# the static library
add_library(cppotp STATIC
	src/libcppotp/bytes.cpp
	src/libcppotp/otp.cpp
	src/libcppotp/sha1.cpp
)

# the binary
add_executable(encrypt
	src/encrypt.cpp
)
target_link_libraries(encrypt
	cppotp
)
