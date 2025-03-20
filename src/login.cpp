#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include "headers/encryption.h"





int make_login(std::string &password, std::string &program_data, bool &logged_in) {

    std::filesystem::create_directory(program_data);
    std::cout << "Create New Password: ";
    std::cin >> password;
    std::cout << "Your password has been set to: " << password << std::endl;
    std::ofstream ofs(program_data + "/login.txt");
    std::string salt = generate_salt();
    std::vector<unsigned char> hash = generate_hash(salt, password);
    std::string hash_string = hash_to_string(hash);
    ofs << salt << " " << hash_string;
    ofs.close();
    logged_in = true;
    return 0;
}

void login(bool & logged_in) {

    std::string password;

    //Check if HOME Exists
    const char *home = std::getenv("HOME");
    if(!home) {
        std::cout << "Could not determine the path to HOME" << std::endl;
        exit(1);
    }



    std::string program_data = std::string(home) + "/.local/share/" + "password_manager";
    if(!std::filesystem::exists(program_data)) {
        make_login(password, program_data, logged_in);
        return;
    }

    std::ifstream inf(program_data + "/login.txt");
    std::string line;
    std::getline(inf, line);
    inf.close();

    while(!logged_in) {
        std::cout << "Enter Password: " ;
        std::cin >> password;
        std::stringstream ss(line);

        std::string word;
        std::vector<std::string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        std::vector<unsigned char> hash = generate_hash(words[0], password);
        std::string hash_string = hash_to_string(hash);

        if(hash_string == words[1]) {
            logged_in = true;
        } else {
            std::cout << "Incorrect Password please try again" << std::endl;
        }
    }
}

