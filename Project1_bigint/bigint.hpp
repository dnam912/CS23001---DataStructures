#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

/*
   * Nadine Nam
   * Project 1 - Milestone 1
   * CS 23001
*/


// (1) The capacity of the bigint
// must be specified by a global constant in bigint.hpp
const int CAPACITY = 200; // maxint


class bigint {
public:
    // (2)
    // A default constructor to initialize a bigint to zero.
    bigint();

    // (3)
    // A constructor to initialize a bigint to an int value 
    // you provide [0, maxint].
    // Example: bigint(128).
    bigint(int);

    // (4)
    // A constructor to initialize a bigint to a const char[] you provide.
    // You can assume what is provided is a valid bigint.
    //Example: bigint("299793"). // "299793" --> char array
    bigint(const char[]);

    // (5)
    // Develop a method called debugPrint that will be helpful 
    // for debugging your bigint. Use a method defintition 
    // of void debugPrint(std::ostream&) const; 
    // It simply prints out every element of your bigint array starting 
    // from the highend (e.g., capacity-1) of the bigint to zero. 
    // Printing a "|" between each value will also be pretting helpful 
    // to help with debugging.
    void debugPrint(std::ostream&) const;

    // (6) Overload output operator<< as a friend or free function,
    // so that takes a stream and bigint as input
    // and writes the bigint to the stream.
    // It will print at most 80 digits per line.
    // No leading zeros are to be printed.
    // std::ostream& operator<<(std::ostream&);
    friend std::ostream& operator<< (std::ostream&, const bigint&);

    // (7) Overload operator== to compare if two bigints are equal.
    // It returns a bool - true if equal and false otherwise.
    bool operator== (const bigint&) const;


private:
    int BIG_INT[CAPACITY];


};


#endif
