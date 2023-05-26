#pragma once
#include "permutation_tree.h"

class PermutationActivator
{
    private:
        std::string* m_data;
        int m_data_length = 0;

    public:
        PermutationActivator(short, short);
        void activator(void*());
};