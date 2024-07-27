#ifndef MENUS_HPP_
#define MENUS_HPP_

#include "specialization.hpp"

/**
 * @brief Show main menu and get user choice
 *
 * @return int Returns user choice, otherwise -1 if invalid choice
 */
int main_menu();

/**
 * @brief Show specialization menu and get user choice
 *
 * @param specialization[] Specializations array
 * @param num_of_specializations
 * @return int Returns specialization index, otherwise -1 for invalid choice
 */
int specialization_menu(Specialization *specializations[],
                             int num_of_specializations);

#endif // MENUS_HPP_