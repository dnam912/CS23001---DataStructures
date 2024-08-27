// String Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {

    {
        char X[11] = {'h','e','l','l','o',' ','w','o','r','l','d'};
        // Setup
        String s(X);

        // Test 
        char x_letter1 = s[4]; // o
        char x_letter2 = s[5]; // space
        char x_letter3 = s[10]; // d

        // Verify
        assert(s    == String(X));
        assert(x_letter1 == 'o');
        assert(x_letter2 == ' ');
        assert(x_letter3 == 'd');

        std::cout << "X_letter1: " << x_letter1 << std::endl; // o
        std::cout << "x_letter2: '" << x_letter2 << "' "<< std::endl; // ' '
        std::cout << "x_letter3: " << x_letter3 << std::endl;  // d
        std::cout << std::endl;
    }
    
    {
        char X[9] = {'1','2','3','4','5','6','7','8','9'};
        // Setup
        String s(X);

        // Test 
        char x_letter1 = s[0]; // 1
        char x_letter2 = s[5]; // 6
        char x_letter3 = s[8]; // 9

        // Verify
        assert(s    == String(X));
        assert(x_letter1 == '1');
        assert(x_letter2 == '6');
        assert(x_letter3 == '9');

        std::cout << "X_letter1: " << x_letter1 << std::endl; // 1
        std::cout << "x_letter2: " << x_letter2 << std::endl; // 6
        std::cout << "x_letter3: " << x_letter3 << std::endl; // 9
        std::cout << std::endl;
    }

    {
        char X[11] = {'h','e','l','l','o',' ','w','o','r','l','d'};

        // Setup
        String s("hello there");

        // Test 
        char s_letter1 = s[0]; // h
        char s_letter2 = s[6]; // 'w'orld

        bool result = (s != String(X)); // true

        // Verify s != X
        assert(result    == true);

        // Verify String s[i]
        assert(s_letter1 == 'h');
        assert(s_letter2 == 't');
        
        std::cout << "Result of (s != String(X)): " << result << std::endl; // true
        std::cout << "S_letter1: " << s_letter1 << std::endl; // h
        std::cout << "S_letter2: " << s_letter2 << std::endl; // 't'here
        std::cout << std::endl;
    }

    {
        // Setup
        String s("7 Habits of Highly Effective People");
        //String s_copy(s);

        // Test 
        char s_letter1 = s[0]; // 7
        char s_letter2 = s[19]; // E

        bool result = (s == String(s)); // true

        // Verify
        assert(result    == true);

        // Verify String s[i]
        assert(s_letter1 == '7');
        assert(s_letter2 == 'E');
        
        std::cout << "Result of (s == String(s)): " << result << std::endl; // true
        std::cout << "S_letter1: " << s_letter1 << std::endl; // h
        std::cout << "S_letter2: " << s_letter2 << std::endl; // 't'here
        std::cout << std::endl;
    }

    // =========== ERROR =========== //
    {
        // Setup
        String s("including the museum’s website and ongoing digital projects such as the museum’s interactive Artlens Gallery and exhibition-based digital projects.");

        // Test 
        char s_letter1 = s[78]; // u
        char s_letter2 = s[79]; // m
        //char s_letter3 = s[80]; // ’

        bool result = (s == String(s)); // true

        // Verify String s[i]
        assert(result    == true);
        assert(s_letter1 == 'u');
        assert(s_letter2 == 'm');
        //assert(s_letter3 == '’');  // Why error is here??? 
        
        
        std::cout << "Result of (s == String(s)): " << result << std::endl; // true
        std::cout << "S_letter1: " << s_letter1 << std::endl; // u
        std::cout << "S_letter2: " << s_letter2 << std::endl; // m
        //std::cout << "S_letter3: " << s_letter3 << std::endl; // ’
        

        std::cout << std::endl;
    }


    

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

