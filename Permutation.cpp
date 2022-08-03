#include "Permutation.h"

template<class T>
void Permutation<T>::display(long long& item)
{
    std::string bit = std::bitset<8>(item).to_string();
    std::cout << bit << std::endl;
}

template<class T>
void Permutation<T>::oneConstant(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {

            std::string m_perms = "";

            if(j != i)
            {
                for(int w = 0; w < size; w++)
                {
                    if(w == i)
                        m_perms.push_back('1');

                    else if(w == j)
                        m_perms.push_back('1');

                    else
                        m_perms.push_back('0');
                }

                // TEST CODE
                    // std::cout << m_perms << std::endl;

                long long num = std::bitset<64>(m_perms).to_ullong();

                if(!(tree.contains(num)))
                    tree.add(num);
                    
                
            }
        }
    }

    std::cout << "#Perms for One Constant = " << tree.getNumberOfNodes() << std::endl;
    
    // TEST CODE
        // std::cout << "Tree Height = " << tree.getHeight() << std::endl;
    
    tree.clear();
}

template<class T>
void Permutation<T>::twoConstant(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int a = 0; a < size; a++)
        {
            if(a!= i)
            {
                for(int j = 0; j < size; j++)
                {

                    std::string m_perms = "";

                    if(j != i && j != a)
                    {
                        for(int w = 0; w < size; w++)
                        {
                            if(w == i)
                                m_perms.push_back('1');

                            else if(w == a)
                                m_perms.push_back('1');

                            else if(w == j)
                                m_perms.push_back('1');

                            else
                                m_perms.push_back('0');
                        }

                        // TEST CODE
                            std::cout << m_perms << std::endl;

                        // long long num = std::bitset<64>(m_perms).to_ullong();

                        // if(!(tree.contains(num)))
                        //     tree.add(num);
                            
                        
                    }
                }
            }
        }
    }

    // std::cout << "#Perms for Two Constant = " << tree.getNumberOfNodes() << std::endl;

    // TEST CODE
        // std::cout << "Tree Height = " << tree.getHeight() << std::endl;
        // tree.preorderTraverse(display);

    // tree.clear();
}

template<class T>
void Permutation<T>::threeConstant(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int a = 0; a < size; a++)
        {
            if(a!= i)
            {
                for(int b = 0; b < size; b++)
                {
                    if(b!= i && b!=a)
                    {
                        for(int j = 0; j < size; j++)
                        {

                            std::string m_perms = "";

                            if(j != i && j != a && j!=b)
                            {
                                for(int w = 0; w < size; w++)
                                {
                                    if(w == i)
                                        m_perms.push_back('1');

                                    else if(w == a)
                                        m_perms.push_back('1');

                                    else if(w == b)
                                        m_perms.push_back('1');

                                    else if(w == j)
                                        m_perms.push_back('1');

                                    else
                                        m_perms.push_back('0');
                                }

                                // TEST CODE
                                    // std::cout << m_perms << std::endl;

                                long long num = std::bitset<64>(m_perms).to_ullong();

                                if(!(tree.contains(num)))
                                    tree.add(num);
                                    
                                
                            }
                        }
                    }
                } 
            }
        }
    }

    std::cout << "#Perms for Three Constant = " << tree.getNumberOfNodes() << std::endl;

    // TEST CODE
        // std::cout << "Tree Height = " << tree.getHeight() << std::endl;
        // tree.preorderTraverse(display);

    tree.clear();
}

template<class T>
void Permutation<T>::permutationCreator(int size, int constants, int count)
{
    if(count == 0)
    {
        m_permutation.clear();

        for(int i = 0; i < size; i++)
            m_permutation.push_back(0);

        for(int i = 0; i < size; i++)
        {
            m_position = m_permutation.begin();
            for(int j = 0; j < i; j++)
                m_position++;

            count++;
            *m_position = 1;
            permutationCreator(size,constants,count);
            count--;
            
            m_position = m_permutation.begin();
            for(int j = 0; j < i; j++)
                m_position++;

            *m_position = 0;
        }
    }

    else if(count != constants && count != 0)
    {
        for(int i = 0; i < size; i++)
        {
            m_position = m_permutation.begin();
            for(int j = 0; j < i; j++)
                m_position++;

            if(*m_position == 0)
            {
                count++;
                *m_position = 1;
                permutationCreator(size,constants,count);
                count--;
                
                m_position = m_permutation.begin();
                for(int j = 0; j < i; j++)
                    m_position++;

                *m_position = 0;
            }
        }

    }

    else if(count == constants)
    {
        for(int i = 0; i < size; i++)
        {
            m_position = m_permutation.begin();

            for(int j = 0; j < i; j++)
                m_position++;

            if(*m_position == 0)
            {
                std::string m_perms = "";

                *m_position = 1;
                m_position = m_permutation.begin();

                for(int k = 0; k < size; k++)
                {
                    if(*m_position == 1)
                        m_perms.push_back('1');

                    else if(*m_position == 0)
                        m_perms.push_back('0');

                    m_position++;
                }

                // TEST CODE
                    std::cout << m_perms << std::endl;
                
                m_position = m_permutation.begin();
                for(int j = 0; j < i; j++)
                    m_position++;

                *m_position = 0;
            }

        }


        // long long num = std::bitset<64>(m_perms).to_ullong();

        // if(!(tree.contains(num)))
        //     tree.add(num);
    }

    // std::cout << "#Perms for Three Constant = " << tree.getNumberOfNodes() << std::endl;

    // TEST CODE
        // std::cout << "Tree Height = " << tree.getHeight() << std::endl;
        // tree.preorderTraverse(display);

    // tree.clear();
}

template<class T>
void Permutation<T>::fourConstant(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int a = 0; a < size; a++)
        {
            if(a!= i)
            {
                for(int b = 0; b < size; b++)
                {
                    if(b!= i && b!=a)
                    {
                        for(int c = 0; c < size; c++)
                        {
                            if(c!= i && c!=a && c!=b)
                            {
                                for(int j = 0; j < size; j++)
                                {

                                    std::string m_perms = "";

                                    if(j != i && j != a && j!=b && j!=c)
                                    {
                                        for(int w = 0; w < size; w++)
                                        {
                                            if(w == i)
                                                m_perms.push_back('1');

                                            else if(w == a)
                                                m_perms.push_back('1');

                                            else if(w == b)
                                                m_perms.push_back('1');

                                            else if(w == c)
                                                m_perms.push_back('1');

                                            else if(w == j)
                                                m_perms.push_back('1');

                                            else
                                                m_perms.push_back('0');
                                        }

                                        // TEST CODE
                                            // std::cout << m_perms << std::endl;

                                        long long num = std::bitset<64>(m_perms).to_ullong();

                                        if(!(tree.contains(num)))
                                            tree.add(num);
                                            
                                        
                                    }
                                }
                            }
                        }
                    }
                } 
            }
        }
    }

    std::cout << "#Perms for Four Constant = " << tree.getNumberOfNodes() << std::endl;

    // TEST CODE
        // std::cout << "Tree Height = " << tree.getHeight() << std::endl;
        // tree.preorderTraverse(display);

    tree.clear();
}

template<class T>
void Permutation<T>::printPattern(int size)
{
    std::string prevConst1 = "";
    std::string prevConst2 = "";
    std::string prevConst3 = "";
    std::string prevConst4 = "";

    for(int n = 1; n <= size; n++)
    {
        std::cout << "\nBool# = " << n << std::endl;
        std::stringstream temp0;
        std::string temp1="";
        std::string temp2="";
        std::string const1="";
        std::string const2="";
        std::string const3="";
        std::string const4="";
        oneConstant(n);
        twoConstant(n);
        threeConstant(n);
        fourConstant(n);
            temp0 << n;
            temp0 >> temp2;
            temp0.clear();

        for(int i = 1; i < size; i++)
        {
            if(i==1 && !(i>=n))
            {


                for(int j = 1; j < n; j++)
                {
                    temp0 << j;
                    temp0 >> temp1;
                    temp0.clear();
                    if(j==1 && n==2)
                        const1 = "f(n = " + temp2 + "){" + "(n-" + temp1 + ")}";

                    else if(j==1 && n!=2)
                        const1 = "f(n = " + temp2 + "){" + "(n-" + temp1 + ")";

                    else if(j==(n-1))
                        const1 += " + (n-" + temp1 + ")}";

                    else
                        const1 += " + (n-" + temp1 + ")";
                }
                
                // TEST CODE
                    std::cout << "\n1 CONSTANT\n" << const1 << std::endl;
                
            }


            if(i==2 && !(i>=n))
            {


                if(i == (n-1))
                {
                    temp0 << i;
                    temp0 >> temp1;
                    temp0.clear();
                    const2 = "f(n = " + temp2 + "){(n-" + temp1 + ")}";
                }

                else if(i != (n-1) && i != n)
                        const2 = prevConst1 + "\n" + prevConst2;

                std::cout << "\n2 CONSTANTS\n" << const2 << std::endl;
            }

            if(i==3 && !(i>=n))
            {


                if(i == (n-1))
                {
                    temp0 << i;
                    temp0 >> temp1;
                    const3 = "f(n = " + temp2 + "){(n-" + temp1 + ")}";
                    temp0.clear();
                }

                else if(i != (n-1) && i != n)
                        const3 = prevConst2 + "\n" + prevConst3;

                std::cout << "\n3 CONSTANTS\n" << const3 << std::endl;
            }

            if(i==4 && !(i>=n))
            {


                if(i == (n-1))
                {
                    temp0 << i;
                    temp0 >> temp1;
                    const4 = "f(n = " + temp2 + "){(n-" + temp1 + ")}";
                    temp0.clear();
                }

                else if(i != (n-1) && i != n)
                        const4 = prevConst3 + "\n" + prevConst4;

                std::cout << "\n4 CONSTANTS\n" << const4 << std::endl;
            }
            
            if (i==(size-1))
            {
                prevConst1 = const1;                
                prevConst2 = const2;
                prevConst3 = const3;
                prevConst4 = const4;
                // std::cout << "PrevConst1 = " << prevConst1 << std::endl;
                // std::cout << "PrevConst2 = " << prevConst2 << std::endl;
            }
        }
    }
}