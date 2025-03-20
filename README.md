# Password Manager

A simple password manager that stores or your passwords locally (and encrypts them).

## How it works

Uses SHA256 (plus salt) and AES256 to encrypt and decrypt all passwords you enter and store them on your machine.

It does this using the OPENSSL EVP library

## Installation

1. In the build directory run ```cmake``` and it should create an executable.
2. Run the program using ```./main``` .

## TODO

[x] Setup Login
[x] Create Dashboard
[x] Save passwords to file
[x] Salt Master Password 
[x] Encrypt Master Password
[ ] Encrypt Passwords file
[ ] Decrypt Passwords file

