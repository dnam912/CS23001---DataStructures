//  Stack class test program
//
//  Tests: test_dtor
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
        stack<int> int_stack1;
        int_stack1.push(1);
        int_stack1.push(2);
        int_stack1.push(3);
        int_stack1.push(4);
        int_stack1.push(5);

        // TEST
        stack<int> *x = &int_stack1;

        delete x;

        // VERIFY
        assert(x == nullptr);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> str_stack1;

        // TEST
        str_stack1.push("hello");
        str_stack1.push("nmklehase");
        str_stack1.push("nasdklfnqefsdnfae");
        str_stack1.push("auoiejnjnsfjiojepafdas");
        str_stack1.push("askjfqpeijfpdos");
        str_stack1.push("ljaisjd9ij9ijiojwoejfasdfasj9");
        str_stack1.push("jaofjeijasdf");
        str_stack1.push("njui jkjinjknkjnsadasfimimmmqesadfj");

        stack<String> *x = &str_stack1;

        delete x;

        // VERIFY
        assert(x == nullptr);
    }

    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     // TEST
    //     stack<int> s;

    //     // VERIFY
    //     assert(s.empty());
    // }


    std::cout << "Done testing dtor." << std::endl;
    return 0;
}

