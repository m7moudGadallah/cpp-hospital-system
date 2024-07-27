#ifndef PATIENT_QUEUE_HPP_
#define PATIENT_QUEUE_HPP_

#include <string>

struct PatientQueueNode {
    std::string patient_name;
    PatientQueueNode *next;
};

struct PatientQueue {
    PatientQueueNode *head;
    PatientQueueNode *tail;
    int size;
};

/**
 * @brief Create a patient queue object
 *
 * @return PatientQueue* Pointer to the patient queue object, otherwise nullptr
 * if memory allocation fails
 */
PatientQueue *create_patient_queue();

/**
 * @brief Create a patient queue node object
 *
 * @param patient_name Patient name
 * @return PatientQueueNode* Pointer to the patient queue node object, otherwise
 * nullptr if memory allocation fails
 */
PatientQueueNode *create_patient_queue_node(std::string patient_name);

/**
 * @brief Enqueue a patient to the patient queue
 *
 * @param queue Pointer to Patient queue
 * @param patient_name Patient name
 * @return int 0 if the patient is successfully enqueued, otherwise -1
 */
int enqueue_patient(PatientQueue **queue, std::string patient_name);

/**
 * @brief Dequeue a patient from the patient queue
 *
 * @param queue Pointer to Patient queue
 * @return string Patient name if the patient is successfully dequeued,
 * otherwise ""
 */
std::string dequeue_patient(PatientQueue **queue);

/**
 * @brief Clear and deallocate the memory of the patient queue node object
 *
 * @param queue Patient queue
 * @return void
 */
void clear_patient_queue(PatientQueue **queue);

#endif // PATIENT_QUEUE_HPP_