#include "../include/specialization.hpp"
#include "../include/system.hpp"
#include <iostream>

const int NUM_OF_SPECIALIZATIONS = 20;
const int SPECIALIZATION_CAPACITY = 5;
Specialization SPECIALIZATIONS[NUM_OF_SPECIALIZATIONS];

int main(void) {
    std::string specialization_names[] = {"Cardiology",
                                          "Neurology",
                                          "Oncology",
                                          "Pediatrics",
                                          "Orthopedics",
                                          "Gastroenterology",
                                          "Dermatology",
                                          "Radiology",
                                          "Anesthesiology",
                                          "Pulmonology",
                                          "Endocrinology",
                                          "Children",
                                          "Urology",
                                          "Obstetrics and Gynecology (OB/GYN)",
                                          "Rheumatology",
                                          "Ophthalmology",
                                          "Psychiatry",
                                          "Infectious Disease",
                                          "Emergency Medicine",
                                          "General Surgery"};

    init_specializations(specialization_names, SPECIALIZATIONS,
                         NUM_OF_SPECIALIZATIONS, SPECIALIZATION_CAPACITY);

    while (true) {
        int status_code = run_system(SPECIALIZATIONS, NUM_OF_SPECIALIZATIONS);
        if (status_code == -2)
            return 0;
        std::cout << "------------------------------------------\n\n";
    }
    return 0;
}
