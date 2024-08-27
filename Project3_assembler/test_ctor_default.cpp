//  Stack class test program
//
//  Tests: test_ctor_default
//

#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> s;

        // VERIFY
        assert(s.empty());
        
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char> s;

        // VERIFY
        assert(s.empty());
        
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> s;

        // VERIFY
        assert(s.empty());
        
    }



    std::cout << "Done testing test_ctor_default." << std::endl;
    return 0;
}

