#include "../include/system.hpp"
#include "../include/actions.hpp"
#include "../include/menus.hpp"
#include <iostream>

const int NUM_OF_SYS_ACTIONS = 5;
int (*SYS_ACTIONS[])(Specialization specializations[],
                     int num_of_specializations) = {
    nullptr, add_patient_action, print_patients_action, pick_patient_action,
    exit_action};

int init_specializations(std::string specialization_names[],
                         Specialization specializations[],
                         int num_of_specializations,
                         int specialization_capacity) {
    for (int i = 0; i < num_of_specializations; i++) {
        specializations[i] = *create_specialization(specialization_names[i],
                                                    specialization_capacity);
    }
    return 0;
}

int run_system(Specialization specializations[], int num_of_specializations) {
    int choice = main_menu();

    if (choice <= 0 or choice >= NUM_OF_SYS_ACTIONS) {
        std::cout << "Invalid choice\n";
        return -1;
    }

    // Call the selected action function
    return SYS_ACTIONS[choice](specializations, num_of_specializations);
}