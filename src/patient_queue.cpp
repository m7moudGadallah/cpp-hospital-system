#include "../include/patient_queue.hpp"

PatientQueue *create_patient_queue() {
    PatientQueue *queue = (PatientQueue *)malloc(sizeof(PatientQueue));

    if (!queue)
        return nullptr;

    queue->head = nullptr;
    queue->tail = nullptr;
    queue->size = 0;

    return queue;
}