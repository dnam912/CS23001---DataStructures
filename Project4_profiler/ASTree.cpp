//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2024 Kent State University. All rights reserved.
//  Spring 2024
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


///////////////////////////// srcML /////////////////////////////
//
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}


//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}


//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}


///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}



//
//AST::
//
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


///////////////////////////// AST /////////////////////////////
// Destructor for AST
//
/*
AST::~AST() {
    //TODO: IMPLEMENT
    //Recursively traverse tree and delete from bottom up
    
    if (!child.empty())
    {
        std::list<AST*>::iterator index = child.begin();
        // Go into the root nodes children and delete them
        for (index = child.begin(); index != child.end(); ++index)
        {
            // this delete causes a recursive call of dtors from contained
            // objects implicity resulting in simple clearing of sub trees
            // and leaf nodes
            delete *index;
        }
    }
}
*/

AST::~AST() {
    //TODO: IMPLEMENT
    //Recursively traverse tree and delete from bottom up

    if ( !child.empty() )
    {
        std::list<AST*>::iterator ptr = child.begin();

        while ( (ptr != child.end()) ) {
            delete *ptr;
            ++ptr;
        }
    }
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //TODO: IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;

    for (std::list<AST*>::const_iterator i = actual.child.begin();
                                         i != actual.child.end(); ++i) {
        child.push_back(new AST(**i));
    }
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //TODO: IMPLEMENT
    //Swap all the top level childern (pointers to AST)

    std::list<AST*> tempPtr = rhs.child; // std::list<AST*> *tempPtr = &rhs.child; ??
    rhs.child = child;
    child = tempPtr;
}
////////////////////////////////////////////////////////////////


/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}



// ============================== MILESTONE 2 ============================== //
//
//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) {
    
    // std::cout << "==== DEBUG START ====> AST:mainHeader()" << std::endl;
    // std::list<AST*>::iterator ptr1 = child.begin();
    // std::cout << "DEBUG: " << (*ptr1) << std::endl;
    // (*ptr1)->print(std::cout);

    // while (ptr1 != child.end()) {
    //     if ((*ptr1)->tag == "function") {

            
    //         std::cout << "DEBUG NAME: ";
    //         (*ptr1)->getChild("block")->print(std::cout);
    //         AST* ptr2 = (*ptr1)->getChild("block");
    //         std::cout << std::endl;
    //     }
    //     ++ptr1;
    // }
    // std::cout << "==== DEBUG END ====> AST:mainHeader()" << std::endl;





    //TODO: IMPLEMENT
    std::list<AST*>::iterator ptr = child.begin();

    while (ptr != child.end()) {
        // 1. Skip down a couple lines or find main and put it before it
        if ((*ptr)->tag == "function") {
            
            // 2. Add a node with #include "profile.hpp"
            std::string line = "#include \"profile.hpp\" \n";
            child.insert(ptr, new AST(token, line));

            // 3. For each file profile name, add a node with a profile
            // 4. declaration "profile foo_cpp("foo.cpp");"
            std::string line2 = "";
            for (size_t i = 0; i < profileName.size(); ++i) {
                // profileName[i] --> foo_cpp
                // fileName[i] --> foo.cpp
                line2 = "profile " + profileName[i] + "(\"" + fileName[i] + "\"); \n\n";
                child.insert(ptr, new AST(token, line2));
            }
            break;
        }
        ++ptr;
    }
    
}

//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {
    // foo.cpp

    //TODO: IMPLEMENT
    // 1. Skip down a couple lines or find first function and put it before it

    std::list<AST*>::iterator ptr = child.begin();

    while (ptr != child.end()) {
        if ((*ptr)->tag == "function") {
            // 2. Add #include "profile.hpp"
            std::string line = "#include \"profile.hpp\" \n";
            child.insert(ptr, new AST(token, line));

            // 3. Add in the external declaration for that file "extern profile foo_cpp;"
            // in fileHeader, profileName is not vector
            std::string line2 = "extern profile " + profileName + ";\n\n";
            
            child.insert(ptr, new AST(token, line2));

            break;
        }
        ++ptr;
    }
}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //TODO: IMPLEMENT
    std::list<AST*>::iterator ptr = child.begin();

    // 1. Find the function with name of "main" in the file
    while (ptr != child.end()) {

        if (((*ptr)->tag == "function")) {
            if ((((*ptr)->getChild("name"))->child.front())->text == "main") {
                break;
            }
        } 
        ++ptr;
    }

    // 2. -Get the "block" node of this function
    AST* ptr_block = ((*ptr)->getChild("block"))->getChild("block_content");  

    // 3. -Set an iterator to the child.end() of "block"
    // 4. -Decrement it once (to skip the "}")
    auto ptr_block2 = ptr_block->child.end();
    --ptr_block2;


    // 5. -Search backwards for a "return" tag
    while (ptr_block2 != (ptr_block)->child.begin()) {

        if ((*ptr_block2)->tag == "return") {
            break;
        }
        --ptr_block2;
    }


    // 6. -Insert the report statements before the return
    std::string line = "";
    for (size_t i = 0; i < profileName.size(); ++i) {
        line = "std::cout << " + profileName[i] + " << std::endl;\n\n\n\t";
        child.insert(ptr_block2, new AST(nodes::token, line));
    }

}





// ============================== MILESTONE 3 ============================== //
//
// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {
    //TODO: IMPLEMENT
    // for each child in the "unit"

    std::list<AST*>::iterator ptr = child.begin();

    while (ptr != child.end()) {

        // 1. if child is a function, constructor, destructor
        if (((*ptr)->tag == "function")
        || ((*ptr)->tag == "constructor")
        || ((*ptr)->tag == "destructor")) {

            // 2. Find the function name (use AST::getName())
            // 3. Find <block>, then find <block_content>
            AST* ptr_block = ((*ptr)->getChild("block"))->getChild("block_content");
            auto ptr_block2 = ptr_block->child.begin();
            ++ptr_block2;


            // 5. Insert the count as first child in <block_content>
            // Example: main1_cpp.count(__LINE__, "main");
            AST* name_ = (((*ptr)->getChild("name"))->child.front());
            std::string line = "";
            line = profileName + ".count(__LINE__, \"" + (name_)->text + "\");\n\n\t";
            
            child.insert(ptr_block2, new AST(token, line));
        }
        ++ptr;
    }
}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing

    for (std::list<AST*>::const_iterator ptr = child.begin(); ptr != child.end(); ++ptr) {

        if ((*ptr)->nodeType == category) {

            if ((*ptr)->tag == "expr_stmt") {

                std::string line = profileName + ".count(__LINE__);\n\t";
                child.insert(ptr, new AST(nodes::token, line));

            } else {
                if (!isStopTag((*ptr)->tag)) {
                    (*ptr)->lineCount(profileName);
                }
            }

        } else {
            // doing nothing
        }
    }
}

////////////////////////////////////////////////////////////////



///////////////////////////// Four Functions /////////////////////////////
//
// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

