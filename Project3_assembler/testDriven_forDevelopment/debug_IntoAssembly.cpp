#include <iostream>
#include <fstream>
#include <algorithm>

#include "../stack.hpp"
#include "../../string/string.hpp"
#include "../utilities.hpp"


// COMPILE WITH
// test_assembler.cpp


String convertPostfixIntoAssembly(const String& str) {

    std::vector<String> vector_postfix = str.split(' ');
    stack<String> stack_forString;

    String left, right;
    String operators, operand;
    String assembly;

    bool operatorExists;
    int index = 0;
    char counter = '1';


    while (index < int(vector_postfix.size())) {

        operatorExists = detectOperator(vector_postfix.at(index)); 

        if (operatorExists == true) {

            operand = convertOperatorToOpcode(vector_postfix.at(index)); 
            operators = (vector_postfix.at(index));

            right = stack_forString.pop(); 
            left = stack_forString.pop(); 

            String TMP = ("TMP" + String(counter)); // REVIEW
            stack_forString.push(TMP);

            assembly += loadInstruction(left, right, operand, TMP);
            ++counter;

        } else if (operatorExists == false) {
            stack_forString.push(vector_postfix.at(index));
        }

        ++index;
    }
    return assembly;
}


// String convertPostfixIntoAssembly(const String& str) {

//     std::vector<String> vector_postfix = str.split(' ');
//     stack<String> stack_forString; // REQUIRED

//     String left, right, operators;
//     String temp, operand;
//     String assembly, subAssembly;

//     bool operatorExists;
//     int index = 0;
//     char counter = '1';

//     //int i = counter - '0';
//     //std::vector<String> temp;

//     // while (vector_postfix.at(index) != '\0') {
//     while (index < vector_postfix.size()) {

//         operatorExists = detectOperator(vector_postfix.at(index)); // **

//         if (operatorExists == true) {
//             // MU
//             operand = convertOperatorToOpcode(vector_postfix.at(index)); // **
//             operators = (vector_postfix.at(index));
//             // *

//             right = stack_forString.pop(); 
//             left = stack_forString.pop(); 

//             stack_forString.push(left + " " + operators + " " + right);
//             temp = stack_forString.top();
            
//             // --counter; // if counter is 1, pass the decrement
//             String TMP = ("TMP" + String(counter));

//             if (counter == '2') {
//                 right = ("TMP" + String(counter - 1));
//                 subAssembly = loadInstruction(left, right, operand, TMP);

//             } else if ((right != temp) && (left != temp)) {
//                 subAssembly = loadInstruction(left, right, operand, TMP);

//             } else if (counter > '2') {
//                 left =  ("TMP" + String(counter - 2));
//                 right = ("TMP" + String(counter - 1));
//                 subAssembly = loadInstruction(left, right, operand, TMP);
//             }
            
//             assembly += subAssembly;
//             ++counter;

//         } else if (operatorExists == false) {
//             stack_forString.push(vector_postfix.at(index));
//             // --counter;
//         }

//         ++index;
//     }
//     return assembly;

// }


String loadInstruction(const String& left, const String& right,
                       const String& operand, String TMP) {
    String assembly;

    assembly += ("|   LD   |  " + left    + " "               + '\n');
    assembly += ("|   "          + operand + "   |  " + right + '\n');
    assembly += ("|   ST   |  " + TMP + '\n');

    return assembly;
}

String convertOperatorToOpcode(const String& str_operator) {
    
    String operand;

    if (str_operator == "+") {
        operand = "AD";
    } else if (str_operator == "-") {
        operand = "SB";
    } else if (str_operator == "*") {
        operand = "MU";
    } else if (str_operator == "/") {
        operand = "DV";
    }
    return operand;
}


bool detectOperator(const String& str_operator) {

    std::vector<String> vector_operator = {"*", "+", "-", "/"};
    
    // Return vector_TMP
    if (std::find(vector_operator.begin(), vector_operator.end(), str_operator)
        != vector_operator.end()) {

            return true;
        }
    return false;
}

// + * H * * * + A * + B C D F G E J
// J E G F D C B + * A + * * * H * +
String convertPrefixIntoAssembly(const String& str) {

    std::vector<String> vector_prefix = str.split(' ');
    std::vector<String> vector_prefix_reversed;

    String prefixChar;
    int i = int(vector_prefix.size());
    int j = 0;
    while (i > 0) {
        prefixChar = vector_prefix.at(i - 1);
        vector_prefix_reversed.push_back(prefixChar);

        // std::cout << "i: "<< i << " " << std::endl;
        // std::cout << "j: " << j << " " << std::endl;
        // std::cout << "prefix: " << prefixChar << std::endl;

        --i;
        ++j;
    }


    stack<String> stack_forString;
    String left, right;
    String operators, operand;
    String assembly;

    bool operatorExists;
    char counter = '1';
    int index = 0;
    while (index < int(vector_prefix_reversed.size())) {

        operatorExists = detectOperator(vector_prefix_reversed.at(index)); 

        if (operatorExists == true) {

            operand = convertOperatorToOpcode(vector_prefix_reversed.at(index)); 
            operators = (vector_prefix_reversed.at(index));

            right = stack_forString.pop(); 
            left = stack_forString.pop(); 

            String TMP = ("TMP" + String(counter)); // REVIEW
            stack_forString.push(TMP);

            assembly += loadInstruction(left, right, operand, TMP);
            ++counter;

        } else if (operatorExists == false) {
            stack_forString.push(vector_prefix_reversed.at(index));
        }

        ++index;
    }
    return assembly;
}




// ============= MILESTONE 2 ============= //
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
        }
        else {
            if (vector_str.at(index) != '(') {
                stack_forString.push(vector_str.at(index));
            }
        }
        ++index;
    }
    return stack_forString.pop();
};

String convertInfixToPrefix(const String& str) {
 
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
            stack_forString.push(str_operator + " " + left + " " + right);
        }
        else {
            if (vector_str.at(index) != '(') {
                stack_forString.push(vector_str.at(index));
            }
        }
        ++index;
    }
    return stack_forString.pop();
};