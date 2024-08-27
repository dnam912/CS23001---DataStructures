#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_

#include <new>
#include <cassert>
#include "../string/string.hpp"


// ============= MILESTONE 2 ============= //
String convertInfixToPostfix(const String&);
String convertInfixToPrefix(const String&);


// ============= MILESTONE 3 ============= //
String convertPostfixIntoAssembly(const String&);
String convertPrefixIntoAssembly(const String&);

String convertOperatorToOpcode(const String&);
String loadInstruction(const String&, const String&,
                       const String&, String);
bool detectOperator(const String&);



#endif