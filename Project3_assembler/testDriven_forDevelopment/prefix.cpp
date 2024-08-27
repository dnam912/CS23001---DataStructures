#include <iostream>
#include <fstream>

#include "stack.hpp"
#include "utilities.hpp"

/*
*   BONUS FOR M2
*/

////////////////////////////////////////
// COMMAND LINE TO EXCUTE AN OBJECT FILE
//
//  g++ -std=c++11 prefix.cpp stack.hpp utilities.hpp utilities.cpp ../string/string.hpp ../string/string.cpp;
// ./a.out
////////////////////////////////////////


int main() {

    std::ifstream in_data3_1("data3-1.txt");
    std::ifstream in_data3_2("data3-2-1.txt");
    std::ofstream out("prefixOutput.txt");

    // Redirecting cin to read from "input.txt" 
    std::cin.rdbuf(in_data3_1.rdbuf()); 
    std::cin.rdbuf(in_data3_2.rdbuf());
    //std::cout.rdbuf(out.rdbuf()); // Redirecting cout to write to "output.txt" 

    String str1 = "";
    String str2 = "";
    char ch;


    out << "[ data3-1.txt PREFIX ]" << std::endl;

    while (in_data3_1.get(ch)) {

        if (ch != ';') {
            str1 += ch; // add the char

        } else if (ch == ';') {
            std::cout << str1 << std::endl;

            str1 += ch; // ****
            out << convertInfixToPrefix(str1);
            out << std::endl;
            str1 = ""; // *****
        }
    }


    out << std::endl;
    out << "[ data3-2-1.txt PREFIX ]" << std::endl;

    while (in_data3_2.get(ch)) {

        if (ch != ';') {
            str2 += ch; // add the char

        } else if (ch == ';') {
            std::cout << str2 << std::endl;

            str2 += ch; // ****
            out << convertInfixToPrefix(str2);
            out << std::endl;
            str2 = ""; // *****
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "[ Infix to PREFIX converted ]" << std::endl;


    in_data3_1.close();
    in_data3_2.close();
    out.close();

    return 0;
}