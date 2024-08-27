// String Test Program
// 
// Tests:  String& operator+= (const String&);    //Concatenation
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

int main() {

    {
        String X1 = "Hello A ";
        String X2 = "There";
        String result;

        result += X1;
        result += X2;

        std::cout << result << std::endl;
    }

    {
        String X1 = "abcdefg";
        String X2 = "hijklmnop";
        String X3 = "qrstuvwxyz";

        String result;

        result += X1;
        result += X2;
        result += X3;

        std::cout << result << std::endl;
    }

    {
        String X1 = "123";
        String X2 = "456";
        String X3 = "789";

        String result;

        result += X1;
        result += X2;
        result += X3;

        std::cout << result << std::endl;
    }

    {
        String X1 = "!@#$%^&*(&%$%^)(----";
        String X2 = "----)*^%^&*(:";

        String result;

        result += X1;
        result += X2;

        std::cout << result << std::endl;
    }


    std::cout << "Done testing Concatenation" << std::endl;
}

