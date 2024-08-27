//  String class test program
//
//  Tests: XXX 
// 
  
#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        String X1 = "Hello A ";
        String X2(X1);
        
        assert(X2 == X1);
        assert(X2 == "Hello A ");

        std::cout << "X2: " << X2 << std::endl;
    }

    {
        String X1 = "abcdefgdhhsdhjdafhjadfdnfqeihfjsdf";
        String X2(X1);

        assert(X2 == X1);
        assert(X2 == "abcdefgdhhsdhjdafhjadfdnfqeihfjsdf"); //charArray

        std::cout << "X2: " << X2 << std::endl;
    }

    {
        String X1 = "no";
        //har x1[2] = {'n', 'o'};
        String X2(X1); // if you declare a char variable,
                    // then the value goes into char ctor

        //assert(X2 == X1);
        //assert(X2 == "no");

        std::cout << "X2: " << X2 << std::endl;
    }

    {
        const char X1[17] = {'C','o','o','k',' ','a',' ','c','r','e','a','m',' ','s','o', 'u', 'p'};
        //String X1 = "Cook a cream soup";
        String X2(X1); //charArray ctor

        //assert(X2 == X1);
        //assert(X2 == "Cook a cream soup");

        std::cout << "X2: " << X2 << std::endl;
    }
    
    
    std::cout << "Done testing test_ctor_copy." << std::endl;
    return 0;
}

