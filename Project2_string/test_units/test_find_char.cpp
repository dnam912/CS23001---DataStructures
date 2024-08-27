// String Test Program
// 
// Tests:  find_char
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main() {

    {
        std::cout << "========= findChar =========" << std::endl;
        // Setup
        String X = "Green apple";
        std::cout << "String: " << X << std::endl;
        std::cout << X[6] << std::endl;
        std::cout << X[1] << std::endl;

        int result1 = X.findch(0, 'a'); // pos: 6
        int result2 = X.findch(0, 'r'); // pos: 1


        // VERIFY
        assert(result1 == 6);
        assert(result2 == 1);


        if (result1 == 6) {
            std::cout << "pos: " << result1 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        if (result2 == 1) {
            std::cout << "pos: " << result2 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= findChar =========" << std::endl;
        // Setup
        String X = "a1s2d3f4g5h6h7j8k9";
        std::cout << "String: " << X << std::endl;
        std::cout << X[5] << std::endl;
        std::cout << X[14] << std::endl;

        int result1 = X.findch(0, '3'); // pos: 6
        int result2 = X.findch(0, 'j'); // pos: 1

        // VERIFY
        assert(result1 == 5);
        assert(result2 == 14);


        if (result1 == 5) {
            std::cout << "pos: " << result1 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        if (result2 == 14) {
            std::cout << "pos: " << result2 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= findChar =========" << std::endl;
        // Setup
        String X = "sdfghjkl23456789098654sdfghjui";
        std::cout << "String: " << X << std::endl;
        std::cout << X[9] << std::endl;
        std::cout << X[29] << std::endl;

        int result1 = X.findch(0, '3'); // pos: 9
        int result2 = X.findch(0, 'i'); // pos: 29

        // VERIFY
        assert(result1 == 9);
        assert(result2 == 29);


        if (result1 == 9) {
            std::cout << "pos: " << result1 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        if (result2 == 29) {
            std::cout << "pos: " << result2 << std::endl;
        } else {
           std::cout << "NOT FOUND" << std::endl;
        }

        std::cout << std::endl;
    }


    {
        std::cout << "========= findChar =========" << std::endl;
        // Setup
        String X = "sdfghjk";
        std::cout << "String: " << X << std::endl;
        std::cout << X[5] << std::endl;
        std::cout << X[4] << std::endl;

        int result1 = X.findch(5, 'j'); // pos: 5
        int result2 = X.findch(5, 'h'); // pos: -1

        // VERIFY
        assert(result1 == 5);
        assert(result2 == -1);

        std::cout << "pos: " << result1 << std::endl;
        std::cout << "pos: " << result2 << std::endl;

        std::cout << std::endl;
    }


    {
        std::cout << "========= findChar =========" << std::endl;
        // Setup
        String X = "sd";
        std::cout << "String: " << X << std::endl;
        std::cout << X[0] << std::endl;
        std::cout << X[1] << std::endl;

        int result1 = X.findch(0, 'j'); // pos: -1
        int result2 = X.findch(0, 'd'); // pos: 1

        // VERIFY
        assert(result1 == -1);
        assert(result2 == 1);

        std::cout << "pos: " << result1 << std::endl;
        std::cout << "pos: " << result2 << std::endl;

        std::cout << std::endl;
    }



    std::cout << "Done testing test_find_char" << std::endl;
    
    return 0;
}

