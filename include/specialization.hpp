#ifndef SPECIALIZATION_HPP_
#define SPECIALIZATION_HPP_

#include "patient_queue.hpp"
#include <string>

struct Specialization {
    std::string name;
    int capacity;
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
 * @brief Clear and deallocate the memory of the specialization object
 *
 * @param specialization Specialization object
 * @return void
 */
void clear_specialization(Specialization **specialization);

#endif // SPECIALIZATION_HPP_