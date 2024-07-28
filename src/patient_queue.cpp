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

PatientQueueNode *create_patient_queue_node(std::string patient_name) {
    PatientQueueNode *node =
        (PatientQueueNode *)malloc(sizeof(PatientQueueNode));

    if (!node)
        return nullptr;

    node->patient_name = patient_name;
    node->next = nullptr;

    return node;
}