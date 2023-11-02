// Really Accurate Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "number.h"

int main()
{
    try
    {
        Number n1("400");
        Number n2("1");
        //Number n3("1");
        std::cout << n1.print() << std::endl;
        //std::cout << n2.print() << std::endl;
        n1.round(4,true);
        //n1.add(&n2);
        for (size_t i = 0; i <= n1.getNumOfDigits(); i++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
        std::cout << n1.print() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
    }
    //cout << "Welcome to Really Accurate Calculator.\nPlease input your function using '0-9','.','+','-','*','/[sig figs]','^[sig figs]','root[sig figs]','ans', and '()'.\n: ";
    
}
