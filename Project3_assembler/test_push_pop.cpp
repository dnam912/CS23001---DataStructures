//  Stack class test program
//
//  Tests: test_push_pop
//

#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        stack<long int> int_stack;

        int_stack.push(1);
        int_stack.push(2);
        int_stack.push(3);

        int_stack.push(1000);
        int_stack.push(100000000);
        int_stack.push(126879878902);
        int_stack.push(923678345617828734);


        // TEST
        assert(int_stack.pop() == 923678345617828734);
        assert(int_stack.pop() == 126879878902);
        assert(int_stack.pop() == 100000000);
        assert(int_stack.pop() == 1000);

        assert(int_stack.pop() == 3);
        assert(int_stack.pop() == 2);
        assert(int_stack.pop() == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;

        // TEST
        string_stack.push("apple");
        string_stack.push("orange");
        string_stack.push("lemon");

        // VERIFY
        assert(string_stack.pop() == "lemon");
        assert(string_stack.pop() == "orange");
        assert(string_stack.pop() == "apple");     
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;

        // TEST
        string_stack.push("hello");
        string_stack.push("nmklehase");
        string_stack.push("nasdklfnqefsdnfae");
        string_stack.push("auoiejnjnsfjiojepafdas");
        string_stack.push("askjfqpeijfpdos");
        string_stack.push("ljaisjd9ij9ijiojwoejfasdfasj9");
        string_stack.push("jaofjeijasdf");
        string_stack.push("njui jkjinjknkjnsadasfimimmmqesadfj");


        // VERIFY
        assert(string_stack.pop() == "njui jkjinjknkjnsadasfimimmmqesadfj");
        assert(string_stack.pop() == "jaofjeijasdf");
        assert(string_stack.pop() == "ljaisjd9ij9ijiojwoejfasdfasj9");   
        assert(string_stack.pop() == "askjfqpeijfpdos");
        assert(string_stack.pop() == "auoiejnjnsfjiojepafdas");
        assert(string_stack.pop() == "nasdklfnqefsdnfae");
        assert(string_stack.pop() == "nmklehase");  
        assert(string_stack.pop() == "hello");
    }
    
    
    std::cout << "Done testing test_push_pop." << std::endl;
    return 0;
}

