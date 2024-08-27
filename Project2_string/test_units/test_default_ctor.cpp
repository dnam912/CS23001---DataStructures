// String Test Program
// 
// Tests:  default constructor, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"
//#include "string-mile2.hpp"

//===========================================================================
int main () {
    // Setup
    String s;

    // Verify
    assert(s[0] == '\0');
    
    // Test 
    std::cout << "0 == " << s << std::endl;


    /*
    0 == 
    Done testing default constructor.

    Question: 
    This is the result of compiling.
    How to make the zero appears in the right side? 
    Does the zero look like disappeared since it is the NULL value?
    */

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

