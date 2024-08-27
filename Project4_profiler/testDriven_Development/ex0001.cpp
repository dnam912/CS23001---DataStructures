#include <iostream>
#include <string>
#include "./ASTree.hpp"

/* Execution Command:
g++ ex0001.cpp ASTree.cpp ; ./a.out
*/



int main() {
    std::cout << "==== ==== ==== ex0000 ==== ==== ====" << std::endl;
    srcML code; //Source code to be profiled.
    std::ifstream inFile("simple.cpp.xml");    //Read in the main
    inFile >> code;

    AST* ASTpointer = code.getTreeASTNode(); // Print root nodes
    std::cout << "getChild( ): ";
    ASTpointer->getChild("function")->print(std::cout);


    // AST* ptr1 = ASTpointer->getChild();



    // .getChild("cpp:include");
    std::list<AST*>::iterator ptr = child.begin();
    std::cout << "==== DEBUG START ====> AST:mainHeader()" << std::endl;
    std::cout << "DEBUG: " << (*ptr) << std::endl;
    (*ptr)->print(std::cout);

    std::cout << "DEBUG: " << (*ptr)->getName() << std::endl;
    std::cout << "DEBUG: " << (*ptr)->getName() << std::endl;


    // for (ptr; ptr != child.end(); ptr++) {
    //     std::cout << (*ptr)->getName() << std::endl;
    // }


    


}



/*
    // .getChild("cpp:include");
    std::cout << "==== DEBUG START ====> AST:mainHeader()" << std::endl;
    std::list<AST*>::iterator tmpPtr;
    // std::cout << "DEBUG: " << (*tmpPtr) << std::endl;
    // (*tmpPtr)->print(std::cout);

    // std::cout << "DEBUG: " << (*ptr)->getName() << std::endl;
    // std::cout << "DEBUG: " << (*ptr)->getName() << std::endl;


    for (tmpPtr = child.begin(); tmpPtr != child.end(); tmpPtr++) {
        std::cout << (*tmpPtr)->getName() << std::endl;
    }
    std::cout << "==== DEBUG END ====> AST:mainHeader()" << std::endl;

*/