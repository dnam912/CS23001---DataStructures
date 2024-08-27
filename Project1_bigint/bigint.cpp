#include <iostream>
#include "bigint.hpp"
// NO vector,string,math


/*
   * Nadine Nam
   * Project 1 - Milestone 1
   * CS 23001
*/


// ============================== MILESTONE 1 ============================== //

// ======================= DEFAULT CONSTRUCTOR ======================= //
bigint::bigint() {
    
    // ASSIGN ZERO in EACH INDEX OF THE ARRAY
    for (int i = 0; i < CAPACITY; ++i) {
        BIG_INT[i] = 0;
    }
}

// ======================= CONSTRUCTOR (int) ======================= //
bigint::bigint(int maxint) {

    int digit = 0;

    // ASSIGN EACH DIGIT INTO ARRAY ELEMENTS
    for (int i = 0; i < CAPACITY; ++i) {
        digit = maxint % 10;
        BIG_INT[i] = digit;
        maxint = maxint / 10;
    }

    // // ASSIGN EACH DIGIT INTO ARRAY ELEMENTS (REVERSED)
    // for (int i = (CAPACITY-1); i < CAPACITY && i >= 0; --i) {
    //     digit = maxint % 10;
    //     BIG_INT[i] = digit;
    //     maxint = maxint / 10;
    // }
}

// ======================= CONSTRUCTOR (char[]) ======================= //
bigint::bigint(const char bigint_char[]) /*: bigint()*/ {

    int size = 0;

    // COUNTING SIZE of bigint_char[]
    while (bigint_char[size] != '\0') {
        ++size;
    }

    // ASSIGNING A VALUE into the array
    //ver 1
    int j = 0;
    for (int i = (size - 1); i >= 0; --i) {
        BIG_INT[j] = int(bigint_char[i]) - int('0');
        ++j;
    }
    // IF no :bigint(), then write this code to assgin zeros in the rest
    for ( ; j < CAPACITY; j++) {
        BIG_INT[j] = 0;
    }


    // ASSIGNING A VALUE in REVERSED
    // int j = (CAPACITY - 1);
    // for (int i = (size - 1); i >= 0 ; --i) {
    //     BIG_INT[j] = int(bigint_char[i]) - int('0');
    //     --j;
    // }
    // for ( ; j >= 0; --j) {
    //     BIG_INT[j] = 0;
    // }
}

// ======================= DEBUGGING ======================= //
void bigint::debugPrint(std::ostream& outstream) const {

    // outstream << "DEBUG: ";
    // for (int j = 0; j < CAPACITY; ++j) {
    //     outstream << " | " << "[" << BIG_INT[j] << "]";
    // }
    // outstream << std::endl;

    outstream << "DEBUG: ";
    for (int j = (CAPACITY - 1); j < CAPACITY && j >= 0; --j) {
        outstream << " | " << "[" << BIG_INT[j] << "]";
    }
    outstream << std::endl;
}

// ==================== BOOL EQUAL OPERATOR== ===================== //
bool bigint::operator== (const bigint &other) const {

    for (int i = 0; i < CAPACITY; ++i) {
        if (this->BIG_INT[i] != other.BIG_INT[i]) {
            return false;
        }
    }

    return true;
}

// ==================== OVERLOADING OUTPUT OPERATOR<< ===================== //
std::ostream& operator<< (std::ostream &outstream, const bigint &object) {

    int i = (CAPACITY - 1);
    int iterator = 0;


    while (i >= 0) {
            // NOT PRINTING OUT LEADING ZEROS
            if (object.BIG_INT[i] == 0) {
                --i;
            }
            
            if (i < 0)
                std::cout << 0;
            else if (object.BIG_INT[i] != 0) {
                
                for ( ; i < CAPACITY && i >= 0; --i) {
                    outstream << object.BIG_INT[i];

                    ++iterator; //iterate i by for-loop;
                    if (iterator == 70) {
                        outstream << std::endl;
                        //outstream << "[80 DIGITS: ]";
                        //outstream << std::endl;
                        iterator = 0;
                    }
                }
            }
        }
    
    return outstream;

    // SIMPLEST VERSION
    /*
    int coungting = 1;
    bool start = false;
    for (int = CAPACITY - 1; i >= 0; --i) {
        if (!start && object.BIG_INT[i] != 0) start = true;
        if (start) {
            outstream << object.BIG_INT[i];
            
            if (counting == 70) {
                outstream << std::endl;
                counting = 1;
            }
            counting++;
        }
    }
    if (!start) outstream << 0;

    return outream;
    */
}



// ============================== MILESTONE 2 ============================== //

// ==================== OVERLOADING INPUT OPERATOR>> ===================== //
std::istream& operator>> (std::istream& instream, bigint& rhs) {

    // ISTREAM TO CHARACTER ARRAY
    int size = 0;
    int index = 0;
    char ch, ch_array[CAPACITY];

    while ((instream >> ch) && (ch != ';')) {
        ch_array[size] = ch;
        ++size;
    }

    for (int i = (size - 1); i >= 0; --i) {
        rhs.BIG_INT[index] = int(ch_array[i]) - int('0');
        ++index;
    }

    // ASSIGN ZERO
    for (   ; index < CAPACITY; index++) {
        rhs.BIG_INT[index] = 0;
    }
    
        // if(ch != ';') {
        //     rhs.BIG_INT[index] = int(ch) - int('0');
        //     index++;
        // }
        // else if (ch == ';') {
        //     std::cout << std::endl;
        //     return instream;
        // }

    return instream;
}

// ==================== OVERLOADING ADDITION OPERATOR+ ===================== //
bigint bigint::operator+ (const bigint& rhs) const {

    bigint result;
    bool carryFlag = false;

    for (int i = 0; i < CAPACITY; ++i) {

        int carry = 0;
        if (carryFlag) {
            carry = 1;
        }
    
        int addedNumber = this->BIG_INT[i] + rhs.BIG_INT[i] + carry;
        
        if (addedNumber >= 10) {
            result.BIG_INT[i] = addedNumber % 10;
            carryFlag = true;
        } else {
            result.BIG_INT[i] = addedNumber;
            carryFlag = false;
        }
    }
    
    return result;
}

// ==================== OVERLOADING SUBSCRIPT OPERATOR[] ===================== //
int bigint::operator[] (int index) const {
    /*
     It returns the digit where i is the 10i position.
     So the first digit is the the one's place (100)
     and the second digit is 101 (ten's place).
     Example: bigint a(2345); a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 2
    */
    
    return this->BIG_INT[index];
}



// ============================== MILESTONE 3 ============================== //

// ==================== times10 ===================== //
bigint bigint::times10(int powerN) const {

    bigint timesTen;

    for (int i = CAPACITY - powerN - 1; i >= 0 ; --i) {
        timesTen.BIG_INT[i + powerN] = this->BIG_INT[i];
    }

    return timesTen;
}

// ==================== timesDigit ===================== //
bigint bigint::timesDigit(int digit) const {

    bigint result;
    int multiplication;
    int carry = 0;

    for (int i = 0; i < CAPACITY; ++i) {
        multiplication = this->BIG_INT[i] * digit;
        multiplication += carry;
        result.BIG_INT[i] = multiplication % 10;
        carry = multiplication / 10;
    }

    return result;
}
// bigint bigint::timesDigit_draft(int digit) const {
//     // A method bigint timesDigit(int) const;
//     // to multiply a bigint and a single digit integer between 0 and 9
//     // Note that this is different than bigint * int
//     // because there the int will be converted into a bigint automatically
//     // by the constructor so will end up being bigint * bigint.
//
//     bigint result;
//     int multiplication;
//     int ones = 0;
//     int tens = 0;
//
//
//     if (digit == 0) {
//         for (int i = 0; i < CAPACITY; ++i) {
//             result.BIG_INT[i] = 0;
//         }
//
//     } else if (digit == 1) {
//         for (int i = 0; i < CAPACITY; ++i) {
//             result.BIG_INT[i] = this->BIG_INT[i];
//         }
//
//     } else {
//         for (int i = 0; i < CAPACITY; ++i) {
//
//             if (i == 0) {
//                 multiplication = this->BIG_INT[i] * digit;
//             }
//
//             multiplication += tens;
//
//             ones = multiplication % 10;
//             result.BIG_INT[i] = ones;
//
//             tens = multiplication / 10;
//          
//             if ((i + 1) < CAPACITY) {
//                 multiplication = this->BIG_INT[i + 1] * digit;
//             }
//         }
//     }
//     return result;
// }


// ==================== OVERLOADING MULTIPLY OPERATOR* ===================== //
bigint bigint::operator* (const bigint& rhs) const {
    
    bigint result;

    for (int i = 0; i < CAPACITY; ++i) {
        bigint temp1 = this->timesDigit(rhs[i]);
        bigint temp2 = temp1.times10(i);
        result = result + temp2;
    }
    
    return result;

    /*
          00234
        * 00099
    -----------
           2106
       +  21060
      ---------
          23166     

    // 123 * 34 = (123 * 30) + (123 * 4)

    // 123 * 128 = 1 2 8
    //   (123 * 1) * 10^2 
    // + (123 * 2) * 10^1 
    // + (123 * 8) * 10^0
    */

    /*
    Overload operator* to multiply two bigints. 
    Implement this multiply using the shift left and times single digit methods above. 
    For example, given x == 234, x.times10(2) == 23400, that is 234 * 102.
    The algorithm to multiply two bigints is as follows:
        //To compute A * B
        //B[0] is 1's place, B[1] is 10's place, B[2] is 100's place, etc.
        product = 0;
        for i = 0 to maxDigits-1 do
        //product = product + ( (A * B[i]) * 10i )
        temp = A.timesDigit(B[i]);
        product = product + temp.times10(i);
        end for
    */

}
