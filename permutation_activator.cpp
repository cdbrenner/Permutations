#include "permutation_activator.h"

PermutationActivator::PermutationActivator(short digit_length, short variable_count)
{
    PermutationTree tree(digit_length);
    tree.build_sub_data(variable_count);
    m_data_length = tree.get_sub_data_length();
    m_data = new std::string[m_data_length];

    for(int i = 0; i < m_data_length; i++)
    {
        m_data[i] = tree.get_sub_data()[i];
    }
}

void PermutationActivator::activator(void* function())
{
    for(int i = 0; i < m_data_length; i++)
    {
        for(int j = 0; j < m_data[i].length(); j++)
        {
            if(m_data[i].c_str()[j] == '1')
                function();
        }
        std::cout << std::endl;
    }
}