#include <iostream>
#include "permutation_tree.h"
#include "permutation_activator.h"

void* hello()
{
    std::cout << "Hello";
    return 0;
}

int main(int argc, char* argv[])
{

 
    // PermutationTree a(6);
    // std::cout << a.nested_summation(0, 6) << std::endl;

    // p.printPattern(4);

    // if(argc != 3)
    // {
    //     std::cout << "Please provide permutation digit length and variable bit count" << std::endl;
    //     return 0;
    // }

    // PermutationTree a(std::stoi(argv[1]));

    // a.build_sub_data(std::stoi(argv[2]));
    // for(int i = 0; i < a.get_sub_data_length(); i++)
    // {
    //     std::cout << a.get_sub_data()[i] << std::endl;
    // }

    PermutationActivator a(4, 2);
    a.activator(hello);

}