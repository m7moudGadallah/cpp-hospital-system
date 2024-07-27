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
 * @brief Display patients Action
 *
 * @param specializations[] Specializations array
 * @param num_of_specializations Number of specializations
 * @return int
 */
int display_patients_action(Specialization specializations[],
                            int num_of_specializations);

#endif // ACTIONS_HPP_