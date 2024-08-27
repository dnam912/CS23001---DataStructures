#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>

#include "string.hpp"
#include "logentry.hpp"


// const std::vector<String>&
void ex001_convert_SingleDigit_FromStrToInt(std::string strToInt) {
    // STRING-CONVERTING CHAR TO INT
    for (char c: strToInt) {
        std::cout << (c - '0');
    }
    std::cout << std::endl;

    // CONVERTING STRING TO INT
    for (auto iterator = strToInt.begin(); iterator != strToInt.end(); ++iterator) {
        int result = int(*iterator - '0');
        std::cout << result;
    }
    std::cout << std::endl;
}


int ex002_convert_MultiDigits_FromSrToInt(std::string strToInt) {
    
    int bytes = 0;
    int counting = 1;

    for (char c: strToInt) {
        bytes = bytes * 10 + (c - '0');
        std::cout << "[" << counting << "]";
        ++counting;
    }

    return bytes;
}


void addBytes() {
    // const std::vector<string>& bytes
    int sum1 = 100;
    int sum2 = 204000;
    int result = 0;

    result += sum1;
    result += sum2;
    
    std::cout << "Sums: " << result;
    std::cout << std::endl;
}


//std::cout << " ============ LogEntry ============== " << std::endl;
// LogEntry::LogEntry(const String& rhs) {
//     String lhs(rhs);
//     std::vector<String> stringEntries = lhs.split(' ');
//     if (stringEntries.size() == 10) {
//         String bytes = stringEntries[9].substr(0, stringEntries[9].length());
//         std::cout << "LOGENTRY Bytes: " << bytes;
//     }
// }

// const std::vector<LogEntry>& entries
// void ex003_convert_MultiDigits_FromVectorToChar(const std::vector<LogEntry>& strToInt) {
//     // USE SIZE() in VECTOR
//     int number = 0;
//     for (int i = 0; i < int(strToInt.size()); ++i) {
//         numbers.push_back(strToInt[0][i] - '0');
//         std::cout << numbers[i];
//     }
//     // for (int j = 0; j < strToInt[0].length(); ++j) {
//     //     std::cout << numbers[0][j] << std::endl;
//     // }
// }



int main() {

    // {
    //     ex001_convert_SingleDigit_FromStrToInt("1234");

    //     int number = ex002_convert_MultiDigits_FromSrToInt("5678");
    //     std::cout << "Return int: " << number << std::endl;

    //     addBytes();
    // }

    {
      std::cout << "========= strToInt =========" << std::endl;

      String str = "200";
      std::cout << str.length() << std::endl;
      std::cout << convertFromStringToInt(str) << std::endl;
    }

}

/*

        int requestLength = stringEntries[5].length();        // Request
        // this->request = stringEntries[5].substr(1, 3)      
                    // + String(" ") + stringEntries[6];
        this->request = stringEntries[5].substr(1, requestLength);
        this->request += String(" ");
        this->request += stringEntries[6];                    // GET /~darci/

*/