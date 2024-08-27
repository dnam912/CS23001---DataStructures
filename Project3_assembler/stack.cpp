//  Stack class test program
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

int main() {

    stack<int> s1;

    std::cout << "Stack: s1 push() & pop()" << std::endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;

    std::cout << "Stack: s1 copy_ctor" << std::endl;
    stack<int> s2(s1);

    std::cout << "Stack: s2.swap(s3)" << std::endl;
    stack<int> s3;
    s3.push(5);
    s3.push(6);
    s3.push(7);
    s3.push(8);

    s2.swap(s3);

    std::cout << s3.pop() << std::endl;
    std::cout << s3.pop() << std::endl;
    std::cout << s3.pop() << std::endl;
    std::cout << s3.pop() << std::endl;


}