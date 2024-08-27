//  Stack class test program
//
//  Tests: test_ctor_copy
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
        
        stack<int> int_stack_copy(int_stack1);
        
        // VERIFY
        for (int i = 0; i < 5; i++) {
            assert(int_stack1.pop() == int_stack_copy.pop());
        }
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char> char_stack1;

        char_stack1.push('D');
        char_stack1.push('a');
        char_stack1.push('t');
        char_stack1.push('a');
        
        stack<char> char_stack_copy(char_stack1);
        
        // VERIFY
        for (int i = 0; i < 4; i++) {
            assert(char_stack1.pop() == char_stack_copy.pop());
        }
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> str_stack1;

        str_stack1.push("Always");
        str_stack1.push("be");
        str_stack1.push("happy");
        
        stack<String> str_stack_copy(str_stack1);
        
        // VERIFY
        for (int i = 0; i < 3; i++) {
            assert(str_stack1.pop() == str_stack_copy.pop());
        }
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

        stack<String> str_stack_copy(str_stack1);

        // VERIFY
        for (int i = 0; i < 8; ++i) {
            assert(str_stack1.pop() == str_stack_copy.pop());
        }
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<long int> int_stack1;

        // TEST
        int_stack1.push(1);
        int_stack1.push(2);
        int_stack1.push(3);
        int_stack1.push(1000);
        int_stack1.push(100000000);
        int_stack1.push(126879878902);
        int_stack1.push(923678345617828734);

        stack<long int> int_stack_copy(int_stack1);

        // VERIFY
        for (int i = 0; i < 7; ++i) {
            assert(int_stack1.pop() == int_stack_copy.pop());
        }
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing test_ctor_copy." << std::endl;
    return 0;
}

