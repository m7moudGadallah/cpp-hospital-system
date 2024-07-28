#include "../include/specialization.hpp"

Specialization *create_specialization(std::string name, int capacity) {
    Specialization *specialization =
        (Specialization *)malloc(sizeof(Specialization));

    if (!specialization)
        return nullptr;

    PatientQueue *urgent_queue = create_patient_queue();

    if (!urgent_queue) {
        free(specialization);
        return nullptr;
    }

    PatientQueue *regular_queue = create_patient_queue();

    if (!regular_queue) {
        free(specialization);
        free(urgent_queue);
        return nullptr;
    }

    specialization->name = name;
    specialization->capacity = capacity;
    specialization->urgent_patients = urgent_queue;
    specialization->regular_patients = regular_queue;

    return specialization;
}

void clear_specialization(Specialization *specialization) {
    if (!specialization)
        return;

    clear_patient_queue(specialization->urgent_patients);
    free(specialization->urgent_patients);
    clear_patient_queue(specialization->regular_patients);
    free(specialization->regular_patients);
}