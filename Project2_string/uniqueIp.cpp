#include <iostream>
// #include "string.hpp"
// #include "logentry.hpp"
#include <map>
#include <string>


int main() {

    std::cout << "==== ==== Example Program ==== ====" << std::endl;

    std::map<std::string, int> myMap;

    std::string names[] = {"Jake", "Jake", "Jake", "Mary", "Mary", "Ann"};

    //
    // key value: Finding a name by a number

    for (int i = 0; i < 6; i++) {
        if (myMap.find(names[i]) == myMap.end()) {
            myMap[names[i]] = 1;
        } else {
            myMap[names[i]]++;
        }
    }

    for (auto iter = myMap.begin() ; iter != myMap.end(); iter++) {
	    std::cout << iter->first << " : " << iter->second << std::endl;
        if (iter->second == 1) {
            std::cout << iter->first << " is UNIQUE!!!!" << std::endl;
            
        }
    }
    
    return 0;
}
