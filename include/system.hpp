#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "specialization.hpp"
#include <string>

/**
 * @brief Initialize Specializations
 *
 * @param specialization_names Specialization names
 * @param specializations Specializations array
 * @param num_of_specializations number of specializations
 * @param specialization_capacity Specialization patients capacity
 * @return int Returns 0 if success, -1 otherwise
 */
int init_specializations(std::string specialization_names[],
                         Specialization *specializations[],
                         int num_of_specializations,
                         int specialization_capacity);

/**
 * @brief Run System
 *
 * @param specializations Specializations array
 * @param num_of_specializations number of specializations
 * @return int Returns 0 if success, -1 error, -2 signal to exist
 */
int run_system(Specialization *specializations[], int num_of_specializations);

#endif // SYSTEM_HPP_