#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"


/*
   * Nadine Nam
   * Project 2 - Milestone 2 & 3 & 4
   * CS 23001
*/


// ============================== MILESTONE 2 ============================== //

    // str.length() + 1 || str.capacity() + 1
    // --> str.stringSize(== memorySize) from M2

// ==================== CONSTRUCTORS ===================== //
String::String() {

    this->stringSize = 1;
    this->str = new char[stringSize];

    str[0] = '\0';
}

String::String(char ch) {

    if (ch == '\0') {
        this->stringSize = 1;
        this->str = new char[stringSize];

        str[0] = '\0';

    } else {
        this->stringSize = 2;
        this->str = new char[stringSize];

        this->str[0] = ch;
        this->str[1] = '\0';
    }
}

String::String(const char charArray_fromStr[]) {
    
    int size = 0;
    while(charArray_fromStr[size] != 0) {
        ++size;
    }

    this->stringSize = size + 1; // memory size
    this->str = new char[stringSize];

	int i = 0;
	while (charArray_fromStr[i] != 0) { // ****
		if (i >= capacity()) break; // ****
		this->str[i] = charArray_fromStr[i];
		++i;
	}
	this->str[i] = 0;
}


// ******** FIXED with SUBSCRIPT[] ******** //
String::String(const String& rhs) {
    /*
    With the previous code, it kept giving me
    the error of  Assertion `i < length()' failed.
    in the operator subscription.

    Thus I modified operator from <= to <
    and stringSize subtracting one
    */

    // stringSize is memorySize here
    // length() + 1;
    this->stringSize = rhs.stringSize; // **** from (rhs.length() + 1) to rhs.stringSize
    str = new char[stringSize];

    int i = 0;
    for ( ; i < (stringSize - 1); ++i) { // **** from stringSize-1 to stringSize
        str[i] = rhs[i];
    }
    str[i] = '\0';
}

String::~String() {
    delete[] str;
}


// ==================== CONSTANT TIME SWAP ===================== //
void String::swap (String& rhs) {
    char *ch = this->str;
    this->str = rhs.str;
    rhs.str = ch;
    
    int size = this->stringSize;
    this->stringSize = rhs.stringSize;
    rhs.stringSize = size;
}

String& String::operator= (String rhs) {
    swap(rhs);
    return *this;
}


// ==================== LENGTH() & CAPACITY ===================== //
int String::capacity() const {
    return (stringSize - 1);
}

int String::length() const {
    // CLASS INV:   str[length()] == 0 &&
    // length() - returns number of characters in string
    
    /*
    Your length function returns 0 if str[0] == null character.
    Put an if statement before return statement, that if length==0, return 1;
    */
    int length = 0;

    while(this->str[length] != '\0') {
        ++length;
    }
    return length;
}


// ==================== ACCESSTOR & MODIFIER ===================== //
    // Assertion `i < length()' failed
    // within the previous copy_ctor
char& String::operator[] (int i) {  // Modifier
    assert(i >= 0);
	assert(i < length());

    return this->str[i];
}

char String::operator[] (int i) const { // Accessor
    assert(i >= 0);
	assert(i < length());

    return this->str[i];
}


// ==================== CONCATENATION ===================== //
    // Overload operator += and + as concatenation
String& String::operator+= (const String& rhs) {

    // 1. Make a new string with enough memory space to hold
    // characters from this and rhs.
    int newSize = (this->length() + rhs.length() + 1);
    char* newStringPointer = new char[newSize];

    // 2. Copy this characters to result; (copy char by char)
    // If using copy constructor (in 1-2.), consider to expand the memory size larger
    int i = 0;
    while (this->str[i] != '\0') {
        newStringPointer[i] = this->str[i];
        ++i;
    }
    
    // 3. Copy rhs characters to result;
    int j = 0;
    while (rhs.str[j] != '\0') {
        newStringPointer[i] = rhs.str[j];
        ++j;
        ++i;
    }

    // 4. Put the null character at the end.
    newStringPointer[i] = '\0';
    delete[] str;  // delete -> delete[]
    this->stringSize = newSize;
    this->str = newStringPointer;

    return *this;
}

String operator+(String lhs, const String& rhs) {
    return String(lhs) += rhs; // modified + to +=
}


// ==================== BOOL OPERATORS ===================== //
bool String::operator== (const String& rhs) const {

    int i = 0;
    while ((this->str[i] != '\0') && (rhs.str[i] != '\0')
        && this->str[i] == rhs.str[i]) {
        ++i;
    }

    return this->str[i] == rhs.str[i];
}

bool String::operator< (const String& rhs) const {

    int i = 0;
	while ((this->str[i] != '\0') && (rhs.str[i] != '\0')
        && (this->str[i] == rhs.str[i])) {
         ++i;
    }

	return this->str[i] < rhs.str[i];
}


// ========================== SUBSTRING =========================== //
String String::substr (int start, int end) const {
    // "abc - - abc"
    //  123456789
    //  sub(5, 5);
    //  start == 5
    //  end == 5

    //  s       e (inclusive)
    //  a p p l e 
    //  0 1 2 3 4

    if (start < 0) {
        start = 0;
    } else if (start > (length() - 1)) {
        return String("");
    } else if (end > (length() - 1)) {
        end = length() - 1;
    } else if (start > end) {
        return String("");
        // start = end; -> end = start;  --> In this case, endPos is inclusive in this code
    }

    int newSize = ((end - start) + 2);
    char* newStringPointer = new char[newSize];

    int i = 0;
    for (int j = start; j <= end; j++) {
        newStringPointer[i] = this->str[j];
        ++i;
    }
    newStringPointer[i] = '\0';     // [-][\0]

    String result(newStringPointer);
    delete[] newStringPointer;

    return result;
}


// =========================== FIND STRING & CHAR =========================== //
int String::findstr(int startingPos, const String& rhs) const {

    if (startingPos < 0) {
        startingPos = 0;
    }
    else if (startingPos > (length() - 1)) {
        return -1;
    }

    int rhs_length = rhs.length();

    while(this->str[startingPos] != 0){
        if (substr(startingPos, (startingPos + (rhs_length - 1))) == rhs) {
            return startingPos;
        }
        ++startingPos;
    }
    return -1;
}

int String::findch(int pos, char x) const {

    if (pos < 0) {
        pos = 0;
    } else if (pos >= length()) {
        return -1;
    }

    while(this->str[pos] != '\0') {
        if(this->str[pos] == x) {
            return pos;
        }
        ++pos;
    }
    return -1;
}





// ==================== OVERLOADING INPUT>> & OUTPUT<< ===================== //
std::istream& operator>>(std::istream& in, String& rhs) {
    // istream reading characters from a text file

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

    char ch[100];

    if (!in.eof()) {
        in >> ch;
    } else {
        ch[0] = '\0';
    }

    rhs = String(ch);

    return in; 
}

// friend std::ostream&
std::ostream& operator<<(std::ostream& out, const String& rhs) {
    
    out << rhs.str;

	return out;
}


// ==================== BOOL OPERATORS ===================== //
    // <Character Comparison>
    // abc < acc => TRUE
    // 'a' == "a"
    // 'a' != "abc"

    // ex 5 - >= +5
    // ! <    >=
    // ! >=   <
    // ! >    <=
    // ! <=   >

bool operator< (char lhs, const String& rhs) { return String(lhs) < rhs; }
bool operator< (const char lhs[], const String& rhs) { return String(lhs) < rhs; }
bool operator== (char lhs, const String& rhs) { return String(lhs) == rhs; }
bool operator== (const char lhs[], const String& rhs) { return String(lhs) == rhs; }

bool operator!= (const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator>  (const String& lhs, const String& rhs) { return rhs < lhs; }
bool operator>= (const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator<= (const String& lhs, const String& rhs) { return !(rhs < lhs); }



// ============================== MILESTONE 3 & 4 ============================== //

    // findch(int pos, char x) --> return a position of the char
    // substr(int start, int end) --> return string
    
    // s = "abc ef gh"
    //      012345678
    // findch(0, ' ') => 3
    // substr(0, 2) => String => result.push(string)
    //
    // findch(4, ' ') => 6
    // substr(4, 5) => push_back

   // If there are continous multiple empty strings, combine them into one

std::vector<String> String::split(char ch) const {

    std::vector<String> result;

    int startIndex = 0;
    int charIndex = -1;

    while (true) {
        // s = "-a--b-"
        //      012345
        charIndex = findch(startIndex, ch);

        if (charIndex == -1) {
            int endIndex = length() - 1;
            String substrInput = substr(startIndex, endIndex);
            result.push_back(substrInput);
            break;
        } else {
            int endIndex = charIndex - 1;
            String substrInput = substr(startIndex, endIndex);  
            result.push_back(substrInput); 
            startIndex = charIndex + 1;
        }
    }

    return result;
}

int convertFromStringToInt(const String& strToInt) {

    int bytes = 0;
    int i = 0;

    while (strToInt.str[i] != '\0') {
        
        bytes = bytes * 10 + int(strToInt.str[i] - '0');
        ++i;
    }

    return bytes;
}