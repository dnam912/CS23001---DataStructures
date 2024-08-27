// bigint Test Program
//
// Tests:   ==, uses bigint(int)
//
//
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {

    {
        // Setup
        String s1("x"), s2("x");
        bool result = (s1 == s2);

        // Test 
        assert(s1 == "x");
        assert(s2 == "x");
        assert(result == true);

        // Verify
        std::cout << s1 << " == " << s2 << std::endl;
        std::cout << "Result: " << result << std::endl;
        std::cout << std::endl;
    }

    {   // Setup
        String s1("abcd"), s2("abcd");
        bool result = (s1 == s2);

        // Test 
        assert(s1 == "abcd");
        assert(s2 == "abcd");
        assert(result == true);

        // Verify
        std::cout << s1 << " == " << s2 << std::endl;
        std::cout << "Result: " << result << std::endl;
        std::cout << std::endl;
    }

    {   // Setup
        String s1("abad"), s2("abab");
        bool result = (s1 == s2);

        // Test 
        assert(s1 == "abad");
        assert(s2 == "abab");
        assert(result == false);  // 0

        // Verify
        std::cout << s1 << " == " << s2 << std::endl;
        std::cout << "Result: " << result << std::endl;
        std::cout << std::endl;
    }

    {   // Setup
        String s1("x"), s2("xxx");
        bool result = (s1 == s2);

        // Test 
        assert(s1 == "x");
        assert(s2 == "xxx");
        assert(result == false);

        // Verify
        std::cout << s1 << " != " << s2 << std::endl;
        std::cout << "Result: " << result << std::endl;
        std::cout << std::endl;
    }

    {   // Setup
        String s1("1234"), s2("2");
        bool result = (s1 == s2);

        // Test 
        assert(s1 == "1234");
        assert(s2 == "2");
        assert(result == false); // <-the result is false

        // Verify
        std::cout << s1 << " != " << s2 << std::endl;
        std::cout << "Result: " << result << std::endl;
        std::cout << std::endl;
    }


    std::cout << "Done testing ==." << std::endl;
    return 0;
}
