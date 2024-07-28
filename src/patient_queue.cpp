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

int enqueue_patient(PatientQueue **queue, std::string patient_name) {
    if (!queue or !*queue)
        return -1;

    PatientQueueNode *node = create_patient_queue_node(patient_name);

    if (!node)
        return -1;

    if (!(*queue)->head) {
        (*queue)->head = node;
        (*queue)->tail = node;
    } else {
        (*queue)->tail->next = node;
        (*queue)->tail = (*queue)->tail->next;
    }

    (*queue)->size++;

    return 0;
}

std::string dequeue_patient(PatientQueue **queue) {
    if (!queue or !*queue or !(*queue)->size or !(*queue)->head)
        return "";

    PatientQueueNode *front = (*queue)->head;
    (*queue)->head = (*queue)->head->next;
    std::string patient_name = front->patient_name;
    free(front);
    (*queue)->size--;
    return patient_name;
}

void clear_patient_queue(PatientQueue *queue) {
    if (!queue)
        return;

    PatientQueueNode *tmp_node = nullptr;

    while (queue->head) {
        tmp_node = queue->head;
        queue->head = queue->head->next;
        free(tmp_node);
    }

    queue->head = nullptr;
    queue->tail = nullptr;
    queue->size = 0;
}

void traverse_queue(PatientQueue *queue, void (*fp)(PatientQueueNode *node)) {
    if (!queue or !fp)
        return;

    PatientQueueNode *curr = queue->head;

    while (curr) {
        fp(curr);
        curr = curr->next;
    }
}