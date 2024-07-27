#include "../include/system.hpp"

int init_specializations(std::string specialization_names[],
                         Specialization *specializations[],
                         int num_of_specializations,
                         int specialization_capacity) {
    for (int i = 0; i < num_of_specializations; i++) {
        specializations[i] = create_specialization(specialization_names[i],
                                                   specialization_capacity);
    }
    return 0;
}