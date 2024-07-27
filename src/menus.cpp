#include "../include/menus.hpp"

#include <iostream>

int main_menu() {
    std::cout << "Enter your choice:\n";
    std::cout << "1) Add new patient\n";
    std::cout << "2) Print patients\n";
    std::cout << "3) Dr. pickup a patient\n";
    std::cout << "4) Exit\n";

    try {
        std::cout << "\n> ";
        int choice;
        std::cin >> choice;
    } catch (const std::exception &e) {
        return -1;
    }
}

int specialization_menu(Specialization specializations[],
                        int num_of_specializations) {
    std::cout << "Specializations, enter your choice:\n";
    for (int i = 0; i < num_of_specializations; i++) {
        std::cout << i + 1 << ": " << specializations[i].name << "\n";
    }

    try {
        std::cout << "\n> ";
        int choice;
        std::cin >> choice;

        if (choice <= 0 or choice > num_of_specializations)
            return -1;
    } catch (const std::exception &e) {
        return -1;
    }
}