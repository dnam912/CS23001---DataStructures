#include <iostream>
#include <map>
#include <string>


int main(int argc, char *argv[]) {
    
    std::cout << "argc: " << argc << std::endl;

    for (int i = 0; i < argc; i++) {

        std::cout << "argv[" << i << "]: "  << argv[i] << std::endl;

    }

    return 0;
}
// ./a.out 
// -o     <--set a name of executed file (실행 파일 이름을 정해주는것)