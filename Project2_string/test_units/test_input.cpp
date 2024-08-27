// String Test Program
// 
// Tests:  input , uses 
//
//  
#include <iostream> 
#include <fstream>
#include <cassert>
#include "string.hpp"

int main() {
    // test_input is just for OPENING THE FILE OR CLOSING IT
    // we're using the input operator to store the string
    // in our func definition
    // use instream to read the characters
    
    // ========== ========== READ TEXT FILES (istream) ========== ========== //
    {
        std::ifstream in;               // Define input stream
        in.open("log_1_tiny.txt");      // Open a file

        std::cout << "READ TEXT FILES (log_1_tiny.txt)" << std::endl;


        if (!in) { // Make sure file opened correctly
            std::cerr << "File not found: log_1_tiny.txt" << std::endl;
            exit(1);
        }

        // Read file from the start to end
        // Until end of file
        // eof() - to reach the end of text file
        String s;

        while ((!in.eof())) {
            in >> s;

            std::cout << s << std::endl;
        }
        in.close();

        std::cout << std::endl;
    }

    // ========== ========== READ TEXT FILES (istream) ========== ========== //
    {
        std::ifstream in;               // Define input stream
        in.open("log_2_small.txt");      // Open a file

        std::cout << "READ TEXT FILES (log_2_small.txt)" << std::endl;


        if (!in) { // Make sure file opened correctly
            std::cerr << "File not found: log_2_small.txt" << std::endl;
            exit(1);
        }

        // Read file from the start to end
        // Until end of file
        // eof() - to reach the end of text file
        String s;

        while ((!in.eof())) {
            in >> s;
            std::cout << std::endl;

            std::cout << s;
        }
        in.close();

        std::cout << std::endl;
    }

     // ========== ========== READ TEXT FILES (istream) ========== ========== //
    // {
    //     std::ifstream in;               // Define input stream
    //     in.open("log_3_medium.txt");      // Open a file

    //     std::cout << "READ TEXT FILES (log_2_small.txt)" << std::endl;


    //     if (!in) { // Make sure file opened correctly
    //         std::cerr << "File not found: log_3_medium.txt" << std::endl;
    //         exit(1);
    //     }

    //     // Read file from the start to end
    //     // Until end of file
    //     // eof() - to reach the end of text file
    //     String s;

    //     while ((!in.eof())) {
    //         in >> s;

    //         std::cout << s;
    //     }
    //     in.close();

    //     std::cout << std::endl;
    // }

    //  // ========== ========== READ TEXT FILES (istream) ========== ========== //
    // {
    //     std::ifstream in;               // Define input stream
    //     in.open("log_4_user.txt");      // Open a file

    //     if (!in) { // Make sure file opened correctly
    //         std::cerr << "File not found: log_4_user.txt" << std::endl;
    //         exit(1);
    //     }

    //     // Read file from the start to end
    //     // Until end of file
    //     // eof() - to reach the end of text file
    //     String s;

    //     while ((!in.eof())) {
    //         in >> s;

    //         std::cout << s;
    //     }
    //     in.close();

    //     std::cout << std::endl;

    // }


    std::cout << "Done testing input operator>>." << std::endl;
}

