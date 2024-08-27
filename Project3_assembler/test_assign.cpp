//  Stack class test program
//
//  Tests: test_assign
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
        stack<int> int_stack2;

        // TEST
        int_stack1.push(100);
        int_stack2 = int_stack1;

        // VERIFY
        assert(int_stack1.pop() == int_stack2.pop());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<long int> int_stack1;
        stack<long int> int_stack2;

        // TEST
        int_stack1.push(1);
        int_stack1.push(2);
        int_stack1.push(3);
        int_stack1.push(1000);
        int_stack1.push(100000000);
        int_stack1.push(126879878902);
        int_stack1.push(923678345617828734);

        int_stack2 = int_stack1;

        // VERIFY
        for (int i = 0; i < 7; ++i) {
            assert(int_stack1.pop() == int_stack2.pop());
        }
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char> char_stack1;
        stack<char> char_stack2;

        // TEST
        char_stack1.push('d');
        char_stack2 = char_stack1;

        // VERIFY
        assert(char_stack1.pop() == char_stack2.pop());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> str_stack1;
        stack<String> str_stack2;

        // TEST
        str_stack1.push("Testing stack in String");
        str_stack2 = str_stack1;

        // VERIFY
        assert(str_stack1.pop() == str_stack2.pop());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> str_stack1;
        stack<String> str_stack2;

        // TEST
        str_stack1.push("hello");
        str_stack1.push("nmklehase");
        str_stack1.push("nasdklfnqefsdnfae");
        str_stack1.push("auoiejnjnsfjiojepafdas");
        str_stack1.push("askjfqpeijfpdos");
        str_stack1.push("ljaisjd9ij9ijiojwoejfasdfasj9");
        str_stack1.push("jaofjeijasdf");
        str_stack1.push("njui jkjinjknkjnsadasfimimmmqesadfj");

        str_stack2 = str_stack1;

        // VERIFY
        for (int i = 0; i < 8; ++i) {
            assert(str_stack1.pop() == str_stack2.pop());
        }
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing test_assign." << std::endl;
    return 0;
}
