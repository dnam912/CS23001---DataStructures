#include <iostream>
#include <fstream>

#include "../stack.hpp"
#include "../utilities.hpp"
//#include "../../string/string.hpp"


////////////////////////////////////////
// COMMAND LINE TO EXCUTE AN OBJECT FILE
//
// g++ -std=c++11 debug_assembler.cpp debug_IntoAssembly.cpp ../stack.hpp ../../string/string.hpp ../../string/string.cpp ../utilities.hpp; ./a.out
//
////////////////////////////////////////



// int main() {

//     std::cout << "========= DEBUGGING 1 ==========" << std::endl;
//     std::cout << "Infix: ( AX + ( B * C ) ) ;" << std::endl;
//     std::cout << "Postfix: " << convertInfixToPostfix("( AX + ( B * C ) ) ;");
//     std::cout << std::endl;
//     std::cout << convertPostfixIntoAssembly("AX B C * +");
//     std::cout << std::endl;

//     std::cout << "========= DEBUGGING 2 ==========" << std::endl;
//     std::cout << "Infix: ( ( AX + ( B * CY ) ) / ( D - E ) ) ;" << std::endl;
//     std::cout << "Postfix: " << convertInfixToPostfix("( ( AX + ( B * CY ) ) / ( D - E ) ) ;");
//     std::cout << std::endl;
//     std::cout << convertPostfixIntoAssembly("AX B CY * + D E - /");
//     std::cout << std::endl;

//     std::cout << "========= DEBUGGING 3 ==========" << std::endl;
//     std::cout << "Infix: ( ( A + B ) * ( C + E ) ) ;" << std::endl;
//     std::cout << "Postfix: " << convertInfixToPostfix("( ( A + B ) * ( C + E ) ) ;");
//     std::cout << std::endl;
//     std::cout << convertPostfixIntoAssembly("A B + C E + *");
//     std::cout << std::endl;

//     std::cout << "========= DEBUGGING 4 ==========" << std::endl;
//     std::cout << "Infix: ( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) ) ;" << std::endl;
//     std::cout << "Postfix: " << convertInfixToPostfix("( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) ) ;");
//     std::cout << std::endl;
//     std::cout << convertPostfixIntoAssembly("AX BX CY AY + BY + CX * * *");
//     std::cout << std::endl;

//     std::cout << "========= DEBUGGING 5 ==========" << std::endl;
//     std::cout << "Infix: ( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;" << std::endl;
//     std::cout << "Postfix: " << convertInfixToPostfix("( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;");
//     std::cout << std::endl;
//     std::cout << convertPostfixIntoAssembly("H A B C + D * + F * G * E * * J +");
//     std::cout << std::endl;

//     return 0;
// }

int main() {


    std::cout << "========= DEBUGGING 6 ==========" << std::endl;
    std::cout << "Infix: ( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;" << std::endl;
    std::cout << "Postfix: " << convertInfixToPrefix("( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;");
    std::cout << std::endl;
    std::cout << convertPostfixIntoAssembly("H A B C + D * + F * G * E * * J +");
    std::cout << std::endl;

    std::cout << convertPrefixIntoAssembly("+ * H * * * + A * + B C D F G E J");
    std::cout << std::endl;

}