#include <iostream>


void enter_to_continue() {
    std::cout << "Press ENTER to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    return;

} void print_divider() {
    std::cout << "==========================================================================" << std::endl;
}
