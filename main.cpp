
#include <cstdlib>
#include <iostream>
#include <string>

/*HEADER FILES */
#include "src/headers/passwords.h"
#include "src/headers/userinput.h"
#include "src/headers/login.h"

void print_title() {
                                                                       
    std::cout << "\n"

"██████╗  █████╗ ███████╗███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗     \n"
"██╔══██╗██╔══██╗██╔════╝██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗    \n"
"██████╔╝███████║███████╗███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║    \n"
"██╔═══╝ ██╔══██║╚════██║╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║    \n"
"██║     ██║  ██║███████║███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝    \n"
"╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝     \n"
"                                                                       \n"
"███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗██████╗          \n"
"████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝██╔══██╗         \n"
"██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██████╔╝         \n"
"██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██╔══██╗         \n"
"██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║  ██║         \n"
"╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝         \n" << std::endl;

    std::cout << "\n"
        "==========================================================================" << std::endl;
}

void print_menu() {
    print_title();
    std::cout << "OPTIONS" << std::endl;
    std::cout << "1. Get Passwords" << std::endl;
    std::cout << "2. Add Password" << std::endl;
    std::cout << "3. Delete Password" << std::endl;
    std::cout << "4. Logout" << std::endl;
    std::cout << "5. EXIT" << std::endl;
    std::cout << "==========================================================================" << std::endl;
    std::cout << "Enter Option: ";
}



void menu(bool &logged_in, std::string &password) {

    std::string choice;

    print_menu();
    std::cin >> choice;

    int choice_int;

    try {
        choice_int = stoi(choice);
    } catch (std::invalid_argument &err) {
        choice_int = -1;
    }

    switch(choice_int) {
        case 1:
            system("clear");
            std::cout << "Get Passwords" << std::endl;
            print_title();
            get_passwords("PASSWORDS");
            enter_to_continue();
            break;
        case 2:
            system("clear");
            std::cout << "Add Password" << std::endl;
            print_title();
            add_password();

            break;
        case 3:
            system("clear");
            std::cout << "Delete Password" << std::endl;
            print_title();
            delete_password();

            break;
        case 4:
            system("clear");
            std::cout << "Logging out" << std::endl;
            logged_in = false;
            break;
        case 5:
            std::cout << "Exiting" << std::endl;
            std::cout << "Thankyou for using the PASSWORD MANAGER" << std::endl;
            logged_in = false;
            exit(0);
            break;
        default:
            system("clear");
            std::cout << "PLEASE ENTER A PROPER CHOICE" << std::endl;
            return;
    }
    system("clear");
}


int main_loop() {

    bool logged_in = false;
    std::string password;

    system("clear");
    while(true) {
        if (!logged_in) {
            login(logged_in, password);
        }
        else {
            menu(logged_in, password);
        }
    }
    return -1;
}


int main() {
    main_loop();
    return 0;
}
