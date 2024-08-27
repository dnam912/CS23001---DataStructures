// String Test Program
// 
// Tests:  find_string , uses 
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main() {

   {
        std::cout << "========= findStr =========" << std::endl;
        // Setup
        String X = "apple";
        std::cout << "String: " << X << std::endl;

        int sbstr = X.findstr(0, "ple"); // start pos: 2


        // VERIFY
        assert(sbstr == 2);


        if (sbstr == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr pos: " << sbstr << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= findStr =========" << std::endl;
        // Setup
        String X = "raspberry";
        std::cout << "String: " << X << std::endl;

        // start pos: 'p' is at 3, but others are pos NOT FOUND
        int sbstr = X.findstr(0, "ple"); 


        // VERIFY
        assert(sbstr == -1);


        if (sbstr == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr pos: " << sbstr << std::endl;
        }

        std::cout << "start pos: 'p' is at 3, but others are NOT FOUND pos" << std::endl;
        std::cout << std::endl;
    }


    {
        std::cout << "========= findStr =========" << std::endl;
        // Setup
        String X = "raspberry";
        std::cout << "String: " << X << std::endl;

        int sbstr1 = X.findstr(0, "sp");

        // start pos: 'sp' is from 2-3, but start pos is at 3 in findstr()
        int sbstr2 = X.findstr(3, "sp");


        // VERIFY
        assert(sbstr1 == 2);
        assert(sbstr2 == -1);

        

        std::cout << "sbstr1 pos: " << sbstr1 << std::endl;

        if (sbstr2 == -1) {
            std::cout << "NOT FOUND" << std::endl;
        }
        //std::cout << "sbstr2 pos: " << sbstr2 << std::endl;
        std::cout << "In sbstr2, 'sp' is from 2-3, but start pos is at 3 in findstr()";
        std::cout << std::endl;
    }



    return 0;
}

