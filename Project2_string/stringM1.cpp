#include "stringM1.hpp"
//#include "logentry.hpp"
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

/*
   * Nadine Nam
   * Project 2 - Milestone 1
   * CS 23001
*/

// ============================== MILESTONE 1 ============================== //


String::String() { //Empty string

    // ASSIGN ZERO in EACH INDEX OF THE CHAR ARRAY
    for (int i = 0; i < STRING_SIZE; ++i) {
        this->str[i] = '\0';  // 0 vs '\0'
    }
}

// ======================= CONSTRUCTOR (char) ======================= //
String::String(char ch) { //Stirng('x')

    this->str[0] = ch;
    this->str[1] = '\0';
}

// ======================= CONSTRUCTOR (const char[]) ======================= //
String::String(const char charArray[]) : String() { //String("abcd")

    // COUNTING SIZE of charArray[]
    int size = 0;
    while (charArray[size] != '\0') {
        ++size;
    }

    int i = 0;
    while (i < size /*charArray[i] != '\0'*/) {
        this->str[i] = charArray[i];
        ++i;
    }
    this->str[i] = '\0'; // assigning null char
}

// ======================= capacity() ======================= //
int String::capacity() const { //Max chars that can be stored

    return (STRING_SIZE - 1);
}

// ======================= length() ======================= //
int String::length() const {  //returns number of characters in string
    // CLASS INV:   str[length()] == 0 &&

    int length = 0;
    while(this->str[length] != '\0') {
        ++length;
    }
    return length;
}

// ==================== char& operator[] ===================== //
// Accessor & Modifier
char& String::operator[] (int indexForModifier) {
    assert(i >= 0);
	assert(i < length());

    return this->str[indexForModifier];
}

// ==================== char operator[] const ===================== //
// Accessor
char String::operator[] (int indexForAccessor) const {
    assert(i >= 0);
	assert(i < length());

    return this->str[indexForAccessor];
}


// Overload += and + as concatenation
String& String::operator+= (const String& rhs) {    //Concatenation
    int start = length();
    int i = 0;

    while (rhs.str[i] != 0) {
        if ((start + i) >= capacity()) break;

        str[start + i] = rhs.str[i];
        ++i;
    }
    str[start + i] = 0;
    return *this;  // modified the object itself and return itself


    // while (rhs.str[i] != 0) {
    //     result.str[i] = this->str[i];
    //     ++i;

    //     if (this->str[i] == 0) {
    //         int j = i;
    //         result.str[j] = rhs.str[j];

    //         ++j;
    //     }

    // }
    // return result;
}


// ========================== EQUALITY OPERATOR== =========================== //
bool String::operator== (const String& rhs) const {

    int i = 0;
    while ((this->str[i] != '\0')
        && (rhs.str[i] != '\0')
        && this->str[i] == rhs.str[i]) {
         ++i;
    }
    return this->str[i] == rhs.str[i];
}

// ========================== LESS THAN OPERATOR< =========================== //
bool String::operator< (const String& rhs) const {

    int i = 0;
	while ((this->str[i] != '\0')
        && (rhs.str[i] != '\0')
        && (this->str[i] == rhs.str[i])) {
         ++i;
    }
	return this->str[i] < rhs.str[i];
}



// ========================== STRING SUBSTR =========================== //
// Sub from staring to ending positions
String String::substr (int start, int end) const { 

    String result;

    //////////////////////////////
    if (start < 0) {
        start = 0;
    } else if(start > end) {
        return String();
    } else if (end >= length()) {
        end = length() - 1;
        return end;
    }
    //////////////////////////////


    int i = 0;
    while(i <= (end - start)) {   // printing out until the end position
        result[i] = str[i + start];
        ++i;
    }

    // assign zero in the end
    result[i] = '\0';

    return result;
}


// ========================== INT FINDSTR =========================== //
// Location of string starting at a position
int String::findstr(int pos, const String& rhs) const {
    int rhs_size = rhs.length();

    ///////////////////////////
    if (pos < 0) {
        pos = 0;
    }
    else if (pos > (length() - rhs_size)) {  // got help
        return -1;
    }
    ///////////////////////////


    while(this->str[pos] != 0){
        if (substr(pos, (pos + (rhs_size - 1))) == rhs) {
            return pos;
        }
        ++pos;
    }
    return -1;
}


// ========================== INT FINDCH =========================== //
// Location of charater starting at a position
int String::findch(int pos, char x) const {
    //////////////////////////////
    if (pos < 0) {
        pos = 0;
    } else if (pos >= length()) {
        return -1;
    }
    //////////////////////////////

    while(this->str[pos] != '\0'){
        if(this->str[pos] == x){
            return pos;
        }
        ++pos;
    }
    return -1;
}



// ==================== OVERLOADING INPUT OPERATOR>> ===================== //
std::istream& operator>>(std::istream& in, String& rhs) {
    // istream reading characters from a text file

    // PRINTING OUT ALL OF CHARACTERS INCLUDING SPACES AND ENTERS
    // NO-WHITESPACE VERSION
    // char singleChar;
    // while (!in.eof()) {
    //     in >> singleChar;
    //     String sc(singleChar);
    //     rhs += sc;
    // }
    // WHITESPACE VERSION ( std::noskipws)
    // char singleChar;
    // while (!in.eof()) {
    //     in >> std::noskipws >> singleChar;
    //     String sc(singleChar);
    //     rhs += sc;
    // }

    char ch[STRING_SIZE];

    if (!in.eof()) {
        in >> ch;
    } else {
        ch[0] = '\0';
    }

    rhs = String(ch);

    return in; 
}

// ==================== OVERLOADING OUTPUT OPERATOR<< ===================== //
std::ostream& operator<<(std::ostream& out, const String& rhs) {

    for (int i = 0; i < (rhs.length()); ++i) {
        out << rhs.str[i];
    }

    return out;
}




// ================== OUTSIDE OF CLASS (no scope operator) ================== //

// <Character Comparison>
// abc < acc => TRUE
// 'a' == "a"
// 'a' != "abc"

// ex 5 - >= +5
// ! <    >=
// ! >=   <
// ! >    <=
// ! <=   >

String operator+(String lhs, const String& rhs) {
    return String(lhs) + rhs;
}

bool operator==(const char lhs[], const String& rhs) {
    // VERSION 1
    // String lhs_s(lhs);
    // // modified from lhs_s.length() != rhs
    // // to lhs_s.length() != rhs.length()
    // if (lhs_s.length() != rhs.length()) { 
    //     return false;
    // }
    // for (int i = 0; i < lhs_s.length(); i++) {
    //     if (lhs_s[i] != rhs[i]) {
    //         return false;
    //     }
    // }
    // return true;

    // VERSION 2
    return (String(lhs) == rhs);
}

bool operator==(char lhs, const String& rhs) {
    return (String(lhs) == rhs);
}

bool operator< (char lhs, const String& rhs) {
    return (String(lhs) < rhs);
}

bool operator< (const char lhs[],  const String& rhs) {
    return (String(lhs) < rhs);
}

bool operator!= (const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs); 

    // WRONG CODE
    // return !(lhs < rhs);  <----- ERROR!!!
    // return ((lhs < rhs) || (lhs == rhs));
    // OR !(rhs > lhs);  <---- ERROR!!!
}

bool operator>= (const String& lhs, const String& rhs) {
    return  !(lhs < rhs);
}

bool operator> (const String& lhs, const String& rhs) {
    return (rhs < lhs);

    // return (lhs > rhs)  <---- ERROR!!!!!
}


/*
    String& operator+=    (const String&);             //Concatenation

    String  substr        (int, int)            const; //Sub from staring to ending positions
    int     findch        (int,  char)          const; //Location of charater starting at a position
    int     findstr       (int,  const String&) const; //Location of string starting at a position


bool    operator==      (const char[],  const String&);
bool    operator<       (const char[],  const String&);
*/