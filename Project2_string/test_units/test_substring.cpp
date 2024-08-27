// String Test Program
// 
// Tests:  substring , uses
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main() {

    {
        std::cout << "========= substr =========" << std::endl;
        // Setup
        String X = "sdfghjk";
        std::cout << "String: " << X << std::endl;

        String sbstr;
        sbstr = X.substr(3, 6);


        // VERIFY
        assert(sbstr == "ghjk");


        if (sbstr == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr: " << sbstr << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= substr =========" << std::endl;
        // Setup
        String X = "There is a green apple.";
        std::cout << "String: " << X << std::endl;

        String sbstr;
        sbstr = X.substr(11, 21); // green apple


        // VERIFY
        assert(sbstr == "green apple");


        if (sbstr == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr: " << sbstr << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= substr =========" << std::endl;
        // Setup
        String X = "+++ Hakuna Matata +++";
        std::cout << "String: " << X << std::endl;

        String sbstr1, sbstr2;
        sbstr1 = X.substr(0, 9); // +++ Hakuna
        sbstr2 = X.substr(11, 20); // Matata +++


        // VERIFY
        assert(sbstr1 == "+++ Hakuna");
        assert(sbstr2 == "Matata +++");


        if ( sbstr1 == -1 || sbstr2 == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr1: " << sbstr1 << std::endl;
           std::cout << "sbstr2: " << sbstr2 << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= substr =========" << std::endl;
        // Setup
        String X = "Hello World!";
        std::cout << "String: " << X << std::endl;

        String sbstr1, sbstr2;
        sbstr1 = X.substr(6, 11); // World!
        sbstr2 = X.substr(0, 12); // Hello World!' '


        if ( sbstr1 == -1 || sbstr2 == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr1: " << sbstr1 << std::endl;
           std::cout << "sbstr2: " << sbstr2 << " sbstr2 is NOT FOUND" << std::endl;
        }

        std::cout << "because the end pos of sbstr2 is bigger than length()";
        std::cout << std::endl;
    }


    {
        std::cout << "========= substr =========" << std::endl;
        // Setup
        String X = "Hello there";
        std::cout << "String: " << X << std::endl;

        String sbstr1, sbstr2;
        sbstr1 = X.substr(2, 6); // llo t
        sbstr2 = X.substr(0, 10); // Hello there


        if ( sbstr1 == -1 || sbstr2 == -1) {
            std::cout << "NOT FOUND" << std::endl;
        } else {
           std::cout << "sbstr1: " << sbstr1 << std::endl;
           std::cout << "sbstr2: " << sbstr2 << std::endl;
        }

        std::cout << std::endl;

    }

    std::cout << "Done testing substring" << std::endl;

    return 0;
}

