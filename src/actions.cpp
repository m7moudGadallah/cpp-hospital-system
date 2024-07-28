#include "../include/actions.hpp"
#include "../include/menus.hpp"
#include "../include/patient_queue.hpp"
#include "../include/specialization.hpp"
#include <iostream>

int add_patient_action(Specialization *specializations[],
                       int num_of_specializations) {
    // show specialization menu
    int specialization_choice =
        specialization_menu(specializations, num_of_specializations);

    if (specialization_choice < 0)
        return specialization_choice;

    try {
        int num_of_patients =
            specializations[specialization_choice]->urgent_patients->size +
            specializations[specialization_choice]->regular_patients->size;
        if (num_of_patients >=
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
        int num_of_patients =
            specializations[specialization_choice]->urgent_patients->size +
            specializations[specialization_choice]->regular_patients->size;

        if (num_of_patients >=
            specializations[specialization_choice]->capacity) {
            std::cout
                << "Specialization is full, please wait and try again later\n";
            return -1;
        }

        if (!num_of_patients) {
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

        std::cout << patient_name << ", please go with Dr.\n";
    } catch (const std::exception &e) {
        std::cout << "Invalid input\n";
        return -1;
    }
}

void print_urgent_patient(PatientQueueNode *node) {
    std::cout << "name: " << node->patient_name << "\tstatus: urgent\n";
}

void print_regular_patient(PatientQueueNode *node) {
    std::cout << "name: " << node->patient_name << "\tstatus: regular\n";
}

int print_patients_action(Specialization *specializations[],
                          int num_of_specializations) {
    // show specialization menu
    int specialization_choice =
        specialization_menu(specializations, num_of_specializations);

    if (specialization_choice < 0)
        return specialization_choice;

    int num_of_patients =
        specializations[specialization_choice]->urgent_patients->size +
        specializations[specialization_choice]->regular_patients->size;

    if (!num_of_patients) {
        std::cout << "There is no patients in this specialization for now\n";
        return -1;
    }

    traverse_queue(specializations[specialization_choice]->urgent_patients,
                   print_urgent_patient);
    traverse_queue(specializations[specialization_choice]->urgent_patients,
                   print_regular_patient);

    return 0;
}

int exit_action(Specialization *specializations[], int num_of_specializations) {
    for (int i = 0; i < num_of_specializations; ++i) {
        if (specializations[i]) {
            clear_specialization(&specializations[i]);
        }
    }

    return -2;
}