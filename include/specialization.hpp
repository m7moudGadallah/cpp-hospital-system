#ifndef SPECIALIZATION_HPP_
#define SPECIALIZATION_HPP_

#include "patient_queue.hpp"
#include <string>

struct Specialization {
    std::string name;
    int capacity;
    int num_of_patients;
    PatientQueue *urgent_patients;
    PatientQueue *regular_patients;
};

/**
 * @brief Create a specialization object
 *
 * @param name Specialization name
 * @param capacity Specialization capacity, i.e., the maximum number of patients
 * @return Specialization* Pointer to the specialization object, otherwise
 * nullptr if memory allocation fails
 */
Specialization *create_specialization(std::string name, int capacity);

/**
 * @brief Add new patient
 *
 * @param name Patient name
 * @param is_urgent true if the patient is urgent, otherwise false
 * @return int Returns 0 if patient is add successfully, -1 if the
 * specialization is full, and -2 for other errors
 */
int add_patient(std::string name, bool is_urgent);

/**
 * @brief Pick a patient from queue
 *
 * @return std::string Returns patient name if there's patients, otherwise ""
 */
std::string pick_patient();

/**
 * @brief Clear and deallocate the memory of the specialization object
 *
 * @param specialization Specialization object
 * @return void
 */
void clear_specialization(Specialization **specialization);

#endif // SPECIALIZATION_HPP_