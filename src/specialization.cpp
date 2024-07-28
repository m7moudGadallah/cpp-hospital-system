#include "../include/specialization.hpp"

Specialization *create_specialization(std::string name, int capacity) {
    Specialization *specialization =
        (Specialization *)malloc(sizeof(Specialization));

    if (!specialization)
        return nullptr;

    PatientQueue *urgent_queue = (PatientQueue *)malloc(sizeof(PatientQueue));

    if (!urgent_queue) {
        free(specialization);
        return nullptr;
    }

    PatientQueue *regular_queue = (PatientQueue *)malloc(sizeof(PatientQueue));

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