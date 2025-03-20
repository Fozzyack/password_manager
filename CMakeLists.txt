cmake_minimum_required(VERSION 3.16)

project(main)

add_executable(main main.cpp)

add_library(passwords src/passwords.cpp)
add_library(userinput src/userinput.cpp)
add_library(login src/login.cpp)
add_library(encryption src/encryption.cpp)
find_package(OpenSSL REQUIRED)

target_link_libraries(main PRIVATE passwords)
target_link_libraries(main PRIVATE login)
target_link_libraries(passwords PRIVATE userinput)
target_link_libraries(login PRIVATE encryption)
target_link_libraries(encryption OpenSSL::Crypto)

target_link_directories(passwords PRIVATE src/headers)
target_link_directories(userinput PRIVATE src/headers)
target_link_directories(login PRIVATE src/headers)
target_link_directories(encryption PRIVATE src/headers)
