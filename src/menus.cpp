#include "../include/menus.hpp"

#include <iostream>

int main_menu() {
    std::cout << "Enter your choice:\n";
    std::cout << "1) Add new patient\n";
    std::cout << "2) Print patients\n";
    std::cout << "3) Dr. pickup a patient\n";
    std::cout << "4) Exit\n";

    try {
        int choice;
        std::cin >> choice;
    } catch (const std::exception &e) {
        return -1;
    }
}