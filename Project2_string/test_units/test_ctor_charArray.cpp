//  String class test program
//
//  Tests: test_ctor_charArray
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
        String X = "abcd";

        // TEST
        String  str(X);

        // VERIFY
        assert(str == "abcd");
        std::cout << "String str(X): " << str << std::endl;
    }

    {
        //------------------------------------------------------
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;

        // SETUP FIXTURE
        String X1 = "hello world";
        String X2 = "hello there";

        // TEST
        String str1(X1);
        String str2(X2);

        // VERIFY
        assert(str1 != str2);

        std::cout << "String str1(X1): " << str1 << std::endl;
        std::cout << "String str2(X2): " << str2 << std::endl;

        std::cout << "str1(X1) == str2(X2):  ";
        if ( (str1 == str2) == true) {
            std::cout << "TRUE" << std::endl;
        } else
        std::cout << "FALSE" << std::endl;
    }


    // ****** REVISE ****** //
    {
        // REVIEW THIS ERROR IN str[11] //
        //------------------------------------------------------
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;

        // SETUP FIXTURE
        // String(const char[])
        char X[11] = {'h','e','l','l','o',' ','w','o','r','l','d'};

        // TEST
        String str(X);

        // VERIFY
        assert(str[4] == 'o'); // 4
        assert(str[5] == ' '); // 5
        assert(str[10] == 'd'); // 10

        std::cout << "String str: '" << str[4] << "'"<< std::endl; // o
        std::cout << "String str: '" << str[5] << "'"<< std::endl; // ' '
        std::cout << "String str: '" << str[10] << "'"<< std::endl; // d

        

        // =========== DEBUG =========== //
        // why not ''(null char)?
        // why random char is printing out even this index points out null char??
        //std::cout << "String str: '" << str[11] << "'"<< std::endl;

        assert(str[11] == '\0');

        std::cout<< "DEBUGGING str[11]: '" << str[11] << "'" << std::endl; // \0
        std::cout << "String str[12]: '" << str[12] << "'"<< std::endl; // ''
        std::cout << "String str[13]: '" << str[13] << "'"<< std::endl; // ''
        std::cout << "String str[15]: '" << str[15] << "'"<< std::endl; // ''
        
        //std::cout << "String str: '" << str << "'"<< std::endl;
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

    // // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing charArray." << std::endl;
    return 0;
}

