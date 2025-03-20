# Password Manager

A simple password manager that stores or your passwords locally (and encrypts them).

## How it works

- Uses SHA256 (plus salt) and AES256 to encrypt and decrypt all passwords you enter and store them on your machine.
- It does this using the OPENSSL EVP library.
- Uses the master password (raw, unhashed and unsalted) to generate a key which decrypts and encrypts the list of
  passwords.

### Note:
- Whilst the files are encrypted users are still able to delete the password file itself causing loss of data.
- A least the passwords are encrypted.

## Installation

1. In the build directory run ```cmake``` and it should create an executable.
2. Run the program using ```./main``` .

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

