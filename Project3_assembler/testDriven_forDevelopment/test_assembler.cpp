#include <iostream>
#include <fstream>

#include "../stack.hpp"
#include "../utilities.hpp"

////////////////////////////////////////
// COMMAND LINE TO EXCUTE AN OBJECT FILE
//
// g++ -std=c++11 test_assembler.cpp debug_IntoAssembly.cpp ../stack.hpp ../../string/string.hpp ../../string/string.cpp ../utilities.hpp;
//  ./a.out data3-1.txt testOutput.txt
//
////////////////////////////////////////



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
    String postfix = "";
    String prefix = "";
    char ch;
    while (in.get(ch)) {

        if (ch != ';') {
            str += ch;

        } else if (ch == ';') {

            std::cout << str << std::endl;

            str += ch;
            out << "------------------------------------------------------- \n";
            out << "Infix: " << str << '\n';

            // postfix = convertInfixToPostfix(str);
            // out << "Postfix: " << postfix << '\n';

            prefix = convertInfixToPrefix(str);
            out << "Prefix: " << prefix << '\n';
            
            out << convertPrefixIntoAssembly(prefix);
            out << std::endl;
            
            str = "";
            // postfix = "";
            prefix = "";

            std::cout << std::endl;
        }
    }

    std::cout << "[ ASSEMBLER in assemblerOutput.txt ]" << std::endl;


    in.close();
    out.close();

    return 0;
}