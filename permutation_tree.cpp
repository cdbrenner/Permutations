#include "permutation_tree.h"

PermutationTree::PermutationTree(short digit_length)
{
    m_digit_length = digit_length;

    m_data_length = pow(2, digit_length);

    m_data = new std::string[m_data_length];

    build_tree(m_root_ptr,digit_length,0);
}

// PermutationTree::~PermutationTree()
// {
//     delete[] m_data;
//     delete[] m_sub_data;
    
//     // inorder_delete(m_root_ptr);
// }

void PermutationTree::inorder_delete(LinkedBTreeNode<char>* treePtr)
{
  if (treePtr != nullptr)
  {
    inorder_delete(treePtr->getLeftChildPtr());
    delete treePtr;
    inorder_delete(treePtr->getRightChildPtr());
  }
}

LinkedBTreeNode<char>* PermutationTree::get_root()
{
    return m_root_ptr;
}

std::string* PermutationTree::get_data()
{
    return m_data;
}

std::string* PermutationTree::get_sub_data()
{
    return m_sub_data;
}

short PermutationTree::get_digit_length()
{
    return m_digit_length;
}

short PermutationTree::get_data_length()
{
    return m_data_length;
}

short PermutationTree::get_sub_data_length()
{
    return m_sub_data_length;
}

void PermutationTree::add_node(LinkedBTreeNode<char>* sub_tree_ptr, const char& newData, bool left)
{
    LinkedBTreeNode<char>* new_node_ptr = new LinkedBTreeNode<char>(newData);
    
    if(left)
    {
        new_node_ptr->set_bitset(sub_tree_ptr->get_bitset());

        sub_tree_ptr->setLeftChildPtr(new_node_ptr);
    }

    else
    {
        new_node_ptr->set_bitset(sub_tree_ptr->get_bitset());

        sub_tree_ptr->setRightChildPtr(new_node_ptr);
    }
}

void PermutationTree::build_tree(LinkedBTreeNode<char>* sub_tree_ptr, short digit_length, short node_depth)
{
    if(node_depth < digit_length)
    {
        add_node(sub_tree_ptr,'0',true);

        if(node_depth == digit_length - 1)
        {
            m_data[m_data_iterator] = sub_tree_ptr->getLeftChildPtr()->get_bitset();
            m_data_iterator++;
        }
        
        build_tree(sub_tree_ptr->getLeftChildPtr(), digit_length, node_depth + 1);
        
        add_node(sub_tree_ptr,'1',false);

        if(node_depth == digit_length - 1)
        {
            m_data[m_data_iterator] = sub_tree_ptr->getRightChildPtr()->get_bitset();
            m_data_iterator++;
        }
        
        build_tree(sub_tree_ptr->getRightChildPtr(), digit_length, node_depth + 1);
    }

}

int PermutationTree::nested_summation(short variable_bit_count, short delta)
{
    int total = 0;

    if(delta > 2)
    {
        for(int i = 0; i <= variable_bit_count; i++)
        {
            total += nested_summation(i, delta - 1);
        }
    }

    else if(delta == 2)
    {
        for(int i = 0; i <= variable_bit_count; i++)
        {
            total += i + 1;
        }
    }

    // NESTED SUMMATION DOESN'T TRULY WORK FOR (DELTA < 2) BECAUSE (DELTA == 1) INDICATES ONLY ONE MORE
    // BRANCH IS TO BE TRAVERSED, EITHER LEFT OR RIGHT, AND THEN THE FINAL NODE CAN BE IDENTIFIED.
    // I.E., FOR EACH (DELTA == 1), THERE IS 1 NODE, SO THIS IS NOT AN INCREASING SERIES SUMMATION, BUT INSTEAD,
    //A SUM OF (V + 1) ONE'S, WHERE V IS THE REMAINING VARIABLE BIT COUNT AT THE CURRENT SUBTREE HEIGHT.
    else if(delta == 1)
    {
        return variable_bit_count + 1;
    }

    else if(delta == 0)
    {
        return 1;
    }

    return total;

}

int PermutationTree::count_sub_set(short variable_bit_count)
{
    // DELTA REFERS TO THE DIFFERENCE BETWEEN THE TREE HEIGHT AND THE VARIABLE COUNT
    short delta = m_digit_length - variable_bit_count;

    if(delta >= 0)
    {
        return nested_summation(variable_bit_count, delta);
    }

    else
        return 0;
}

void PermutationTree::malloc_sub_data(short variable_bit_count)
{
    m_sub_data_length = count_sub_set(variable_bit_count);
    
    if(m_sub_data_length > 0)
        m_sub_data = new std::string[m_sub_data_length];

    else
    {
        std::cout << "Invalid sub-data variable count - no sub-data array was allocated\n";
        std::cout << "Must satisfy variable bit count <= digit length (i.e. tree height)\n";
    }
}

void PermutationTree::add_sub_data(LinkedBTreeNode<char>* sub_tree, short variable_bit_count, short digit_length)
{
    if(variable_bit_count != 0)
    {
        add_sub_data(sub_tree->getLeftChildPtr(), variable_bit_count - 1, digit_length - 1);

        if(variable_bit_count != digit_length)
        {
            add_sub_data(sub_tree->getRightChildPtr(), variable_bit_count, digit_length - 1);
        }
    }

    else
    {
        if(sub_tree->getRightChildPtr() != nullptr)
        {
            while(sub_tree->getRightChildPtr() != nullptr)
            {
                sub_tree = sub_tree->getRightChildPtr();
            }

            m_sub_data[m_sub_data_iterator] = sub_tree->get_bitset();
            m_sub_data_iterator++;
        }

        else
        {
            m_sub_data[m_sub_data_iterator] = sub_tree->get_bitset();
            m_sub_data_iterator++;
        }
    }
}

void PermutationTree::build_sub_data(short variable_bit_count)
{
    malloc_sub_data(variable_bit_count);

    add_sub_data(m_root_ptr, variable_bit_count, m_digit_length);
}