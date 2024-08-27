//  String class test program
// 
//  Tests: lessThan, uses <
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

        String str1("accd");
        String str2("abcd");

        // TEST
        
        // std::cout << "X1: " << str1 << std::endl;
        bool result = (str1 < str2);

        // VERIFY
        assert(result == false);
        //assert(result == X);

        std::cout << "Result(str1 < str2): " << result << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char X1 = '2';
        char X2 = '1';
        String str1(X1);
        String str2(X2);

        // TEST
        bool result = (X1 > X2);

        // VERIFY
        assert(result == true); 
        std::cout << "Result(X1 > X2): " << result << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String X1 = "12345";
        String X2 = "12345";
        String str1(X1);
        String str2(X2);

        // TEST
        bool result = (str1 < str2);

		std::cout << "X1: " << X1 << std::endl;
		std::cout << "X2: " << X2 << std::endl;

        // VERIFY
        assert(result == false);
        std::cout << "Result: " << result << std::endl;
    }

    {
		// SETUP FIXTURE
		String X1 = "There is a";
		String X2 ("green apple");

        // TEST
    	bool result = (X1 < X2);

		std::cout << "X1: " << X1 << std::endl;
		std::cout << "X2: " << X2 << std::endl;

		if (result == 1) {
			std::cout << "Result is TRUE (X1 < X2):" << result << std::endl;
		} else {
			std::cout << "Result is FALSE (X1 < X2): " << result << std::endl;
		}

		std::cout << " ========== ========== ========== ==========" << std::endl;
		std::cout << std::endl;
	}

	{
		// SETUP FIXTURE
		String X1 = "There is a bear";  // Capital T is 84 in decimal
		String X2 ('b');                // lower case b is 98 in decimal

        // TEST
    	bool result = (X1 < X2);

		std::cout << "X1: " << X1 << std::endl;
		std::cout << "X2: " << X2 << std::endl;
		std::cout << result << std::endl;

		if (result == 1) {
			std::cout << "Result is TRUE (X1 < X2):" << result << std::endl;
		} else if (result == 0) {
			std::cout << "Result is FALSE (X1 < X2): " << result << std::endl;
		}
		
		std::cout << " ========== ========== ========== ==========" << std::endl;
		std::cout << std::endl;
	}

	{
		// SETUP FIXTURE
		String X1 = "there is a bear";  // lower case t is 116 in decimal
		String X2 ('b');                // lower case b is 98 in decimal

        // TEST
    	bool result = (X1 < X2);

		std::cout << "X1: " << X1 << std::endl;
		std::cout << "X2: " << X2 << std::endl;
		std::cout << result << std::endl;

		if (result == 1) {
			std::cout << "Result is TRUE (X1 < X2):" << result << std::endl;
		} else if (result == 0) {
			std::cout << "Result is FALSE (X1 < X2): " << result << std::endl;
		}

		std::cout << " ========== ========== ========== ==========" << std::endl;
		std::cout << std::endl;

	}



    std::cout << "Done testing lessThan operator<." << std::endl;
    return 0;
}



