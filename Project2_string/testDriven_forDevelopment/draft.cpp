#include "string.hpp"
//#include "logentry.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>


// int main() for stringM1.cpp
/*
// int main() {

//     // { 
//     //     std::cout << "========= CHAR =========" << std::endl;
//     //     String s1('X');
//     //     std::cout << s1;
//     //     std::cout << std::endl;

//     //     std::cout << "========= STRING =========" << std::endl;
//     //     String s2("abcd234567dfgty");
//     //     std::cout << s2;
//     //     std::cout << std::endl;
//     // }

//     // {
//     //     std::cout << "========= BOOL EQUAL =========" << std::endl;
//     //     // Setup
//     //     String s3("abcd"), s4("abcd");
//     //     bool result = (s3 == s4);

//     //     // Test 
//     //     assert(s3 == "abcd");
//     //     assert(s4 == "abcd");
//     //     assert(result == true);

//     //     // Verify
//     //     std::cout << s3 << " == " << s4 << std::endl;

//     //     if (result == true) {
//     //         std::cout << "Result: True " << result << std::endl;
//     //     } else {
//     //         std::cout << "Result: False" << std::endl;
//     //     }
//     //     std::cout << std::endl;
//     // }

//     // std::cout << "========= RETURN_DIGIT =========" << std::endl;
//     // // Setup
//     // char X[11] = {'h','e','l','l','o',' ','w','o','r','l','d'};
//     // String s(X);

//     // std::cout << s.length() << std::endl;

//     // s.operator[] (2);
//     // //s.debugPrint(std::cout);

//     // std::cout << "Result of (s != String(X)): " << s << std::endl;
//     // std::cout << "X_letter1: " << x_letter1 << std::endl;
//     // std::cout << "X_letter2: " << x_letter2 << std::endl;

// }
*/






// int String::length() const {
//     // CLASS INV:   str[length()] == 0 &&
//     // length() - returns number of characters in string

//     int length = 0;

//     while(this->str[length] != '\0') {
//         ++length;
//     }
//     return length;
// }

// // ////////////////////////////////////
// std::istream& operator>>(std::istream& input, String& rhs) {
//     // PRINTING OUT ALL OF CHARACTERS INCLUDING SPACES AND ENTERS

//     // char *ch = new char[STRING_SIZE];
//     char ch = *rhs.str; // MUST COMPILE THIS
    
//     input.get(ch);
//     while(!input.eof()) {


//         if (ch == ' ')
//             std::cout << '\n';
//         else
//             std::cout << ch;
//         input.get(ch);
//     }

//     return input;
// }


// // ======================= DEBUGGING ======================= //
// void String::debugPrint(std::ostream& outstream) const {

//     outstream << "DEBUG: ";
//     for (int j = 0; j < STRING_SIZE; ++j) {
//         outstream << " | " << "[" << str[j] << "]";
//     }
//     outstream << std::endl;

//     // outstream << "DEBUG: ";
//     // for (int j = (STRING_SIZE - 1); j < STRING_SIZE && j >= 0; --j) {
//     //     outstream << " | " << "[" << str[j] << "]";
//     // }
//     // outstream << std::endl;
// }



/*
String String::operator+(const String& rhs) const {
    int offset = length();
    String result(str); // avoid copying
    int i = 0;
    while (rhs.str[i] != 0) {
        if ((offset + i) >= Capacity()) break;
        result.str[offset + i] = rhs[i];
        ++i;
    }
    result.str[i] = 0;
    return result;
}

String& String::operator+=(const String& rhs) { // need to modify the object itself so &after String
    int start = length();
    int i = 0;
    while (rhs.str[i] != 0) {
        if ((start + i) >= Capacity()) break;
        str[start + i] = rhs.str[i];
        ++i;
    }
    str[start + i] = 0;
    return *this;  // modified the object itself and return itself
}


String String::substr(int s, int e)const {
    String result;
    if (s < 0) s = 0;
    if (s > e) return String();
    if (e >= length()) return e = length() -1;
    int i = 0;
    while(i<(e-s)){
        result[i] = str[i + s];
        ++i;
    }
    result[i] = 0;
    return result;
}

int String::findChar(char ch, int pos)const {
    if(pos < 0) pos =0;
    if(pos > length()-1) return -1;
    int i = pos;
    while(str[i] != 0){
        if(str[i] == ch){
            return i;
        }
        ++i;
    }
    return -1;
}

int String::findSubstr(const String& s, int pos) const{
    if(pos<0) pos = 0;
    if(pos> length()-s.length()) return -1;

    int i = pos;
    int len = s.length();
    while(str[i]!=0){
        if(substr(i,i+len-1) == s)
            return i;
        ++i;
    }
    return -1;
}



*/
