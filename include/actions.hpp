#ifndef ACTIONS_HPP_
#define ACTIONS_HPP_

#include "specialization.hpp"

/**
 * @brief Add patient action
 *
 * @param specializations[] Specializations array
 * @param num_of_specializations Number of specializations
 * @return int Returns 0 if the patient is added successfully, otherwise -1
 */
int add_patient_action(Specialization specializations[],
                       int num_of_specializations);

/**
 * @brief Pick patient action
 *
 * @param specializations[] Specializations array
 * @param num_of_specializations Number of specializations
 * @return int Returns 0 if the patient is picked successfully, otherwise -1
 */
int pick_patient_action(Specialization specializations[],
                        int num_of_specializations);

/**
 * @brief Print patients Action
 *
 * @param specializations[] Specializations array
 * @param num_of_specializations Number of specializations
 * @return int Returns 0 if success, otherwise -1
 */
int print_patients_action(Specialization specializations[],
                          int num_of_specializations);

/**
 * @brief Exist System
 *
 * @param specializations
 * @param num_of_specializations
 * @return int Returns -2 if success, otherwise -1
 */
int exit_action(Specialization specializations[], int num_of_specializations);

#endif // ACTIONS_HPP_