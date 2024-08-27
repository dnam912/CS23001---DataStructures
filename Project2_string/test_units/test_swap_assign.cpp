 //  String class test program
//
//  Tests: swap_assign
// 

#include "string.hpp"
#include <cassert>
#include <iostream> 
  
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String X("Byebye");
        String X2("Hello");
        //String  str(X);

        assert(X == "Byebye");
        assert(X2 == "Hello");

        // TEST
        X.swap(X2);

        // VERIFY
        assert(X == "Hello");
        assert(X2 == "Byebye");
    }

      {
        //------------------------------------------------------
        // SETUP FIXTURE
        String X("dftyguhijfd7rty");
        String X2("asdjflajeisfjasdfaesd");
        //String  str(X);

        assert(X == "dftyguhijfd7rty");
        assert(X2 == "asdjflajeisfjasdfaesd");

        // TEST
        X.swap(X2);

        // VERIFY
        assert(X == "asdjflajeisfjasdfaesd");
        assert(X2 == "dftyguhijfd7rty");

        std::cout << "X: " << X << std::endl;
        std::cout << "X2: " << X2 << std::endl;
    }

    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE
    //     char X1 = 'n';
    //     char X[6] = {'h', 'o', 'h', 'o', 'h', 'o'};
    //     //String X("hohoho");

    //     // TEST
    //     X[0].swap(X1);
    //     X[2].swap(X1);
    //     X[4].swap(X1);

    //     // VERIFY
    //     assert(XXX == YYY);
    // }

    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE
    //     char X = {};
    //     String  str(X);

    //     // TEST
    //     str.OP();

    //     // VERIFY
    //     assert(XXX == YYY);
    // }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing test_swap_assign." << std::endl;
    return 0;
}

