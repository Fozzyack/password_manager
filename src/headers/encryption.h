#pragma once
#include <openssl/evp.h>
#include <iostream>
#include <random>
#include <vector>


std::string generate_salt();
std::vector<unsigned char> generate_hash(std::string salt, std::string password);
std::string hash_to_string(std::vector<unsigned char> &hash);
