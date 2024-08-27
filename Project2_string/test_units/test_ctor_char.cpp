//  String class test program
//
//  Tests: test_ctor_char 
// 

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;

        // SETUP FIXTURE
        char X = 'h';

        // TEST
        String str(X);

        // VERIFY
        assert(str[0] == 'h' && str[1] == '\0');

        std::cout << "String str: " << str << std::endl;
        std::cout << "String str length(0): " << str.length() << std::endl;
    }

   {
        //------------------------------------------------------
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;

        // SETUP FIXTURE
        char X = '4';

        // TEST
        String str(X);

        // VERIFY
        assert(str[0] == '4' && str[1] == '\0');

        std::cout << "String str[0]: " << str[0] << std::endl;
        std::cout << "String str[1]: '" << str[1] << "'" << std::endl;
        std::cout << "String str length(0): " << str.length() << std::endl;
    }

    {
        //------------------------------------------------------
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;

        // SETUP FIXTURE
        char X = '\0';

        // TEST
        String str(X);

        // VERIFY
        assert(str[0] == '\0');

        std::cout << "String str[0]: " << str[0] << std::endl;
        std::cout << "String str[1]: " << str[1] << std::endl;
        std::cout << "String str length(0): " << str.length() << std::endl;
    }

    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     char X = {};

    //     // TEST
    //     String  str(X);

    //     // VERIFY
    //     assert(str == YYY);
    // }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing ctor_char." << std::endl;
    return 0;
}
