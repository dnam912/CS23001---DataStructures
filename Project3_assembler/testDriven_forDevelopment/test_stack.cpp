#include <iostream>
#include "string.hpp"
#include "stack.hpp"

// HOW TO EXECUTE with string.cpp
// g++ -std=c++11 stack.cpp ../Project2_string/string.cpp; ./a.out


int main() {

    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::cout << s1.pop() << std::endl;

    stack<int> s2(s1);

    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;

    
    return 0;
}