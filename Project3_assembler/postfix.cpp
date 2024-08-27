#include <iostream>
#include <fstream>

#include "stack.hpp"
#include "utilities.hpp"



int main(int argc, char *argv[]) {

    if (argc < 2) {
         std::cerr << "Error: Not Enough Arguments" << std::endl;
    }
    std::ifstream in(argv[1]);
    if (!in && argc == 2) {
        std::cerr << "Error: Can not open the input file" << std::endl;
        exit(1);
    }
    std::ofstream out(argv[2]);
    if (!in && argc == 2) {
        std::cerr << "Cannot be executed" << std::endl;
        exit(2);
    }


    String str = "";
    char ch;

    while (in.get(ch)) {

        if (ch != ';') {
            str += ch;

        } else if (ch == ';') {
            std::cout << str << std::endl;

            str += ch;
            out << "------------------------------------------------------- \n";
            out << "Infix: " << str << std::endl;
            out << "\nPostfix: " << convertInfixToPostfix(str) << std::endl;
            out << "Prefix: " << convertInfixToPrefix(str) << std::endl;
            out << "\n\n";
            str = "";

            std::cout << std::endl;
        }
    }


    std::cout << "[ POSTFIX & PREFIX in dataOutput.txt ]" << std::endl;

    in.close();
    out.close();

    return 0;
}