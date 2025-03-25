#include <fstream>
#include <iostream>
#include "headers/userinput.h"

/*
 * Gets the path for the directory
 * where files are saved
 */
std::string get_path() {
    const char *home = std::getenv("HOME");
    std::string path = std::string(home) + "/.local/share/password_manager/";
    return path;
}

/*
 * Function that adds to the passwords
 * file
 */
int add_to_pwds(std::string &purpose, std::string &password) {
        std::ofstream outf { get_path() + "pws.txt", std::ios::app };
        if(!outf) {
            std::cerr << "File could not be openned for writing\n";
            return 1;
        }

        outf << purpose << " ";
        outf << password << "\n";
        outf.close();

        return 0;
}

/*
 * UI that users enter their password 
 * and purpose for the password in
 */
int add_password() {
    std::cout << "ADD PASSWORD" << std::endl;
    while(true){
        print_divider();
        std::string purpose = "";
        std::string password = "";

        std::cout << "Enter Purpose: ";
        std::cin >> purpose;

        std::cout << "Enter Password: ";
        std::cin >> password;


        if(purpose == "" && password == "") continue;
        



        /*
         * Add the encryption here
         * Then save it to a file
         */

    

        int written = add_to_pwds(purpose, password);
        if (written == 1) return 1;

        std::cout << "Added: " << purpose << " (purpose) " << password << " (password) " << std::endl;


        enter_to_continue();
        return 0;



    }

}

/*
 * Reads from passwords file
 */
int get_passwords(std::string title) {


    std::cout << title << std::endl;
    std::ifstream inf{ get_path() + "pws.txt" };

    if(!inf) {
        std::cerr << "Could not open file" << std::endl;
        std::cerr << "There may be no passwords currently" << std::endl;
        return 1;
    }

    /*
     * Add the decryption here 
     */

    std::string strInput{};
    int count = 1;
    while(std::getline(inf, strInput)) {
        std::cout << count << ": " << strInput << "\n";
        count++;
    }


    return 0;
}

/*
 * Deletes from passwords file. Does this buy writing to
 * another file, deleting the old file, then renaming the 
 * new file.
 */
int delete_password() {

    get_passwords("SELECT WHICH PASSWORD TO REMOVE");
    std::cout << "0 to CANCEL" << std::endl;

    print_divider();
    std::string path = get_path();
    
    std::ifstream inf{ path + "pws.txt" };
    std::ofstream outf{ path + "pws_tmp.txt" };
    std::string line;

    int count = 1;
    int selected;

    std::cout << "Enter NUMBER to DELETE: ";
    std::cin >> selected;

    while(std::getline(inf, line)) {
        if (count != selected) {
            outf << line << std::endl;
        }
        count++;
    }

    inf.close();
    outf.close();
    std::remove((path + "pws.txt").c_str());
    std::rename((path + "pws_tmp.txt").c_str(), (path + "pws.txt").c_str());

    std::cout << "FINISHED DELETING" << std::endl;
    enter_to_continue();
    return 0;
}




