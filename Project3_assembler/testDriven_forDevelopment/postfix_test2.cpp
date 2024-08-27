#include <iostream>
#include <fstream>
// #include <cstdlib>
// #include <cassert>

#include "../stack.hpp"
#include "../utilities.hpp"
#include "../../string/string.hpp"


////////////////////////////////////////
// COMMAND LINE TO EXCUTE AN OBJECT FILE
//
// g++ -std=c++11 postfix_test2.cpp debug_InfixToPostfix.cpp ../utilities.hpp ../stack.hpp ../../string/string.hpp ../../string/string.cpp; ./a.out
//
////////////////////////////////////////


int main() {

    // std::cout << convertInfixToPostfix("( A * ( B * C ) ) ;");
    // std::cout << std::endl;
    // std::cout << convertInfixToPostfix("( ( A - ( B * C ) ) + E ) ;");
    // std::cout << std::endl;
    std::cout << convertInfixToPostfix("( ( A + ( B * C ) ) / ( D - E ) ) ;");
    std::cout << std::endl;
    // std::cout << convertInfixToPostfix("( ( ( A * B ) / C ) - ( ( D + E ) * F ) ) ;");
    // std::cout << std::endl;
    // std::cout << convertInfixToPostfix("( ( AX * BX ) + ( ( ( ( ( ( CX - DY ) * EX ) * FX ) * GY ) * HX ) + JY ) ) ;");
    // std::cout << std::endl;

    return 0;
}


