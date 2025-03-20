#include <iomanip>
#include <openssl/evp.h>
#include <iostream>
#include <random>
#include <openssl/evp.h>
#include <sstream>
#include <vector>


std::string generate_salt() {

    const char alphanum[] = 
        "012345679"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distribution(0, 62);

    std::string salt;
    for(size_t i = 0; i < 200; i++) {
        salt += alphanum[distribution(generator)];
    }
    return salt;

}

std::vector<unsigned char> generate_hash(std::string salt, std::string password) {

    EVP_MD_CTX *mdctx;
    const EVP_MD *md;

    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len, i;

    md = EVP_get_digestbyname("sha256");


    mdctx = EVP_MD_CTX_new();
    if (mdctx == NULL) {
        std::cout << "Message digest create failed" << std::endl;
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestInit_ex2(mdctx, md, NULL)) {
        std::cout << "Message digest Init failed." << std::endl;
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestUpdate(mdctx, salt.c_str(), (size_t)salt.length())) {
        std::cout << "Message digest Update failed." << std::endl;
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestUpdate(mdctx, password.c_str(), (size_t)password.length())) {
        std::cout << "Message digest Update failed." << std::endl;
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    if (!EVP_DigestFinal_ex(mdctx, md_value, &md_len)) {
        std::cout << "Message digest Final failed" << std::endl;
        EVP_MD_CTX_free(mdctx);
        exit(1);
    }
    EVP_MD_CTX_free(mdctx);

    std::vector<unsigned char> hash(md_value, md_value + md_len);
    return hash;
}

std::string hash_to_string(std::vector<unsigned char> &hash) {
    std::stringstream hash_ss;
    for(unsigned char byte: hash) {
        hash_ss << std::setw(2) << std::setfill('0') << std::hex << int(byte);
    }
    return hash_ss.str();
}
