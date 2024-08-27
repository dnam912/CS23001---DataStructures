#include <iostream>
#include <fstream>

#include "../stack.hpp"
#include "../../string/string.hpp"

// COMPILE WITH
// postfix_test2.cpp


String convertInfixToPostfix(const String& str) {
 
    std::vector<String> vector_str = str.split(' ');
    stack<String> stack_forString;
    int index = 0;

    String left;
    String right;
    String str_operator;

    while (vector_str.at(index) != ';') { // Read eof is reached
    
        if (vector_str.at(index) == ')') {
            right = stack_forString.pop();
            str_operator = stack_forString.pop();
            left = stack_forString.pop();
            stack_forString.push(left + " " + right + " " + str_operator);

            std::cout << "right: " << right << std::endl;
            std::cout << "str_operator: " << str_operator << std::endl;
            std::cout << "left" << left << std::endl;
            
            std::cout << "stack_forString1: " << stack_forString.top() << std::endl;
            std::cout << "linked lists1: " << std::endl; stack_forString.print();
            std::cout << std::endl;
        }
        else {
            if (vector_str.at(index) != '(') {
                stack_forString.push(vector_str.at(index));

                std::cout << "stack_forString2: " << stack_forString.top() << std::endl;
                std::cout << "linked lists2: " << std::endl; stack_forString.print();
                std::cout << std::endl;
            }
        }
        ++index;
    }
    return stack_forString.pop();
};

