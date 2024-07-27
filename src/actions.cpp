#include "../include/actions.hpp"
#include "../include/menus.hpp"
#include "patient_queue.hpp"
#include <iostream>

int add_patient_action(Specialization *specializations[],
                       int num_of_specializations) {
    // show specialization menu
    int specialization_choice =
        specialization_menu(specializations, num_of_specializations);

    if (specialization_choice < 0)
        return specialization_choice;

    try {
        if (specializations[specialization_choice]->num_of_patients >=
            specializations[specialization_choice]->capacity) {
            std::cout
                << "Specialization is full, please wait and try again later\n";
            return -1;
        }

        std::string patient_name = "";
        bool is_urgent = false;

        std::cout << "Enter patient name: ";
        std::cin >> patient_name;
        std::cout << "Enter urgency status(1 urgent, 0 regular): ";
        std::cin >> is_urgent;

        int status_code = enqueue_patient(
            &((is_urgent)
                  ? specializations[specialization_choice]->urgent_patients
                  : specializations[specialization_choice]->regular_patients),
            patient_name);

        if (status_code < 0)
            return status_code;

        specializations[specialization_choice]->num_of_patients++;
        std::cout << "Patient added successfully\n";
    } catch (const std::exception &e) {
        std::cout << "Invalid input\n";
        return -1;
    }
}

int pick_patient_action(Specialization *specializations[],
                        int num_of_specializations) {
    // show specialization menu
    int specialization_choice =
        specialization_menu(specializations, num_of_specializations);

    if (specialization_choice < 0)
        return specialization_choice;

    try {
        if (specializations[specialization_choice]->num_of_patients >=
            specializations[specialization_choice]->capacity) {
            std::cout
                << "Specialization is full, please wait and try again later\n";
            return -1;
        }

        if (!specializations[specialization_choice]->num_of_patients) {
            std::cout
                << "No patients in this specialization at the moment, Dr.\n";
            return -1;
        }

        std::string patient_name = dequeue_patient(
            &(specializations[specialization_choice]->urgent_patients));

        if (patient_name == "") {
            patient_name = dequeue_patient(
                &(specializations[specialization_choice]->regular_patients));
        }

        specializations[specialization_choice]->num_of_patients--;
        std::cout << patient_name << ", please go with Dr.\n";
    } catch (const std::exception &e) {
        std::cout << "Invalid input\n";
        return -1;
    }
}