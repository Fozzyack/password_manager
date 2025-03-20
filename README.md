# Password Manager

## Overview

A simple password manager that stores or your passwords locally (and encrypts them).

## Why

I can't remember my passwords and I would like to save them locally to my computer rather than use an external 3rd party
source. I would Also like to store my passwords in some, unreadable format such that they can only be read, deleted and
written to from using this app.

## How it works

- Uses SHA256 (plus salt) and AES256 to encrypt and decrypt all passwords you enter and store them on your machine.
- It does this using the OPENSSL EVP library.
- Uses the master password (raw, unhashed and unsalted) to generate a key which decrypts and encrypts the list of
  passwords.

### Note:

- Whilst the files are encrypted users are still able to delete the password file itself causing loss of data.
- A least the passwords are encrypted.

## Installation

1. In the build directory run ```cmake ..``` and it should create a makefile.
2. In the build directory run ```make``` and it should create an executable.
3. Run the program using ```./main``` .

### Note

Files are saved in ```$HOME/.local/share/password_manager/...```

Therefore if ```$HOME``` is not set or ```$HOME/.local/share``` does not exist. This application will not work.

## TODO

- [x] Setup Login
- [x] Create Dashboard
- [x] Save passwords to file
- [x] Delete passwords from file
- [x] Salt Master Password 
- [x] Encrypt Master Password
- [ ] Encrypt Passwords file
- [ ] Decrypt Passwords file
- [ ] Change Master password

