
#include <iostream>
#include <string>
#include "./ASTree.hpp"


/* Execution Command:

g++ ex0000.cpp ASTree.cpp ; ./a.out

*/

void enumExamples() {
    enum fruit { Apple, Banana, Orange};

    fruit myFruit = Banana;

    if (myFruit == Banana) {
        std::cout << "You have a Banana" << std::endl;
    } else {
        std::cout << "You don't have a Banana" << std::endl;
    }

//----------------------------------------------------------------------


    std::string myFruitStr = "Apple"; // myFruitStr can be either "Apple" "Banana" "Orange"

    myFruitStr = "Grape";

    if (myFruitStr == "Banana") {
        std::cout << "You have a Banana" << std::endl;
    } else if (myFruitStr == "Apple") {
        std::cout << "You don't have a Banana" << std::endl;
    } else if (myFruitStr == "Orange") {
        std::cout << "You don't have a Banana" << std::endl;
    }
}

// segmentation fault is foo.cpp.xml 

int main() {

    std::cout << "==== ==== ==== ex0000 ==== ==== ====" << std::endl;


    srcML code; //Source code to be profiled.
    std::ifstream inFile("simple.cpp.xml");    //Read in the main
    inFile >> code;

    // code.printHeader();

    AST* ASTpointer = code.getTreeASTNode(); // Print root nodes

    // std::cout << "print: ";
    // ASTpointer->print(std::cout);

    // ASTpointer->getChild("name")->print(std::cout);

    //std::cout << "getName(): ";  // nothing printed
    // std::cout << ASTpointer->getName() << std::endl;
    
    std::cout << "getChild(function): ";
    ASTpointer->getChild("function")->print(std::cout);


    return 0;
}
