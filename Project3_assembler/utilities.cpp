#include <iostream>
#include <fstream>
#include <algorithm>

#include "stack.hpp"
#include "utilities.hpp"
#include "../string/string.hpp"


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




// ============= MILESTONE 3 ============= //
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

String convertPrefixIntoAssembly(const String& str) {

    std::vector<String> vector_prefix = str.split(' ');
    std::vector<String> vector_prefix_reversed;

    String prefixChar;
    int i = int(vector_prefix.size());
    // int j = 0;
    while (i > 0) {
        prefixChar = vector_prefix.at(i - 1);
        vector_prefix_reversed.push_back(prefixChar);

        --i;
        // ++j;
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
    
    std::vector<String>::iterator itr = find(vector_operator.begin(), vector_operator.end(), str_operator);
    if (itr != vector_operator.end()) {
            return true;
        }
    return false;
}