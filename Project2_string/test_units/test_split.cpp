// String Test Program
//
// Tests:  split, uses <vector>String split
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    /*
    s = "abc ef gh", then s.split(' ') returns a vector
    with three strings: { "abc", "ef", "gh" }

    s = "-a--b-", then s.split('-') returns a vector
    with five strings: { "", "a", "", "b", "" },
    three of which are empty string.

    The findch() and substr() operators should be used to implement this method.
    */

    /*
    The program opens the file name given on the command line and read from that file. Based on the command line options it will:
    
    Print all the logEntry entries (neatly one per line).
    Print the total number of bytes (last number) of all the logs.
    Print the host (IP address) for each logEntry (one per line).
    */

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //char ch[6] = {'-', 'a', '-', '-', 'b', '-'};
        //String str("abc ef gh");
        String s("-a--b-");
        std::vector<String> result = s.split('-');

        for (int i = 0; i < result.size(); i++) {
            
            // std::cout << "[" << result[i] << "]" << std::endl;
        }

        // // VERIFY
        assert(result[0] == "");
        assert(result[1] == "a");
        assert(result[2] == "");
        assert(result[3] == "b");
        assert(result[4] == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //char ch[6] = {'-', 'a', '-', '-', 'b', '-'};
        //String str("abc ef gh");
        String s("ab cde fg");
        std::vector<String> result = s.split(' ');

        for (int i = 0; i < result.size(); i++) {
            // std::cout << "[" << result[i] << "]" << std::endl;
        }

        // VERIFY
        assert(result[0] == "ab");
        assert(result[1] == "cde");
        assert(result[2] == "fg");

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //char ch[6] = {'-', 'a', '-', '-', 'b', '-'};
        //String str("abc ef gh");
        String s;
        s = "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] 200 5625";
        std::vector<String> result = s.split(' ');

        for (int i = 0; i < result.size(); i++) {
            //std::cout << "[" << result[i] << "]" << std::endl;
        }

        // VERIFY
        assert(result[0] == "131.123.47.176");
        assert(result[1] == "-");
        assert(result[2] == "-");
        assert(result[3] == "[18/Sep/2002:12:05:25");
        assert(result[4] == "-0400]");
        assert(result[5] == "200");
        assert(result[6] == "5625");
    }

    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE
    //     char X = {};
    //     String  str(X);

    //     // TEST
    //     str.OP();

    //     // VERIFY
    //     assert(XXX == YYY);
    // }

    std::cout << std::endl;
    std::cout << "Done testing split." << std::endl;
    std::cout << std::endl;

    return 0;
}