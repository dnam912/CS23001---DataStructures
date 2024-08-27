#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


int main() {
    
    std::ifstream in;            // Define input stream
    in.open("log_2_small.txt");      // Open a file


    if (!in) { // Make sure file opened correctly
        std::cerr << "File not found: log_2_small.txt" << std::endl;
        exit(1);
    }

    // getline()
    // std::cout << "GETLINE(in, string)" << std::endl;
    // std::string log;
    // while (getline(in, log)) {
    //     std::cout << log << std::endl;
    // }
    // std::cout << std::endl;



    // get(char&)
    std::cout << "GET(char&)" << std::endl;
    char c;
    while(!in.eof()) {
        c = in.get();

        std::cout << c;

        // if (c == '\n') {
        //     std::cout << "[-NEW-]"; // NEW is printed out
        // } else if (c == '\0') {
        //     std::cout << "[-NULL-]";
        // }
    }
    std::cout << std::endl;

    in.close();

    return 0;
}


/*
std::vector<LogEntry> parse(std::istream& in) {

    // ================ GETLINE() ================== //
    std::vector<LogEntry> linesOfLogEntry;
    
    int maxSize = 200;
    char temp[200];

    while (!in.eof()) {
        // include reading whitespaces
        // read the whole line
        in.getline(temp, maxSize);
        LogEntry stringsOfLogEntry(temp);
        linesOfLogEntry.push_back(stringsOfLogEntry);
    }
    // for (int i = 0; int(linesOfLogEntry.size()); ++i) {
    //     String lhs(linesOfLogEntry[i]);
    //     std::vector<LogEntry> stringsOfLogEntry = lhs.split(' ');
    // }


    // // ================ GET() ================== //
    // char c;
    // while(!in.eof()) {
    //     c = in.get();

    //     String str(c);
    //     std::vector<LogEntry> stringsOfLogEntry = str.split(' ');
    // }


    return linesOfLogEntry;
}
*/