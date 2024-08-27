//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& rhs) { // Copy const
    // 1. Copy the value from file by &rhs
    // 2. Seperate strings by parse()
    // 3. get value from vector[i]
    std::vector<String> stringEntries = rhs.split(' ');

    if (stringEntries.size() == 10) {
        this->host = stringEntries.at(0);                        // Host

        this->date.setDate( stringEntries.at(3).substr(1,2),     // Day
                            stringEntries.at(3).substr(4,6),     // Month
                            stringEntries.at(3).substr(8,11) );  // Year

        this->time.setTime( stringEntries.at(3).substr(13,14),   // Hour
                            stringEntries.at(3).substr(16,17),   // Minute
                            stringEntries.at(3).substr(19,20) ); // Second

        int requestLength = stringEntries.at(5).length();        // Request
        this->request = stringEntries.at(5).substr(1, requestLength);
        this->request += String(" ");
        this->request += stringEntries.at(6);                    // GET /~darci/

        this->status = stringEntries.at(8);                      // Status

        if (stringEntries.at(9) == '-') {
            this->number_of_bytes = 0;                        // Bytes
        } else {
            int bytesLength = stringEntries.at(9).length();
            String bytes = stringEntries.at(9).substr(0, bytesLength);
            this->number_of_bytes = convertFromStringToInt(bytes);
        }
        
    }
    else if (stringEntries.size() < 10) {
        std::cout << "String size is less than 10." << std::endl;
    }
    else if (stringEntries.size() > 10) {
        std::cout << "String size is bigger than 10." << std::endl;
    }

    /*
    1. - After host //stringEntries.at(1) and .at(2)
    2. -0400] // stringEntries.at(4)
    3. status // stringEntries.at(8)
    */
}


std::ostream& operator<<(std::ostream& out, const LogEntry& logEntry) {
    
        out << logEntry;

    return out;
}


// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {

    std::vector<LogEntry> linesOfLogEntry;
    
    int maxSize = 1000;
    char temp[1000];

    while (!in.eof()) { // read the whole line
        in.getline(temp, maxSize); // include reading whitespaces
        LogEntry stringsOfLogEntry(temp);
        std::cout << stringsOfLogEntry.getHost() << " - " << stringsOfLogEntry.getRequest() << std::endl;
        linesOfLogEntry.push_back(stringsOfLogEntry);
    }
    return linesOfLogEntry;
}


// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& entries) {
    
    int entrySize = entries.size();
    std::cout << "Size of vector<LogEntry>: " << entrySize << std::endl;

    for (int i = 0; i < entrySize; i++) {
        std::cout << "[ LogEntry: " << (i+1) << " ]" << std::endl;
        std::cout << "========== Host ==========" << std::endl;
        out << "Host: " << entries.at(i).getHost() << std::endl;


        std::cout << "========== Date ==========" << std::endl;
        out << "Year: " << entries.at(i).getDate().getYear() << std::endl;
        out << "Month: " << entries.at(i).getDate().getMonth() << std::endl;
        out << "Day: " << entries.at(i).getDate().getDay() << std::endl;


        std::cout << "========== Time ==========" << std::endl;
        out << "Hour: " << entries.at(i).getTime().getHour() << std::endl;
        out << "Minute: " << entries.at(i).getTime().getMinute() << std::endl;
        out << "Second: " << entries.at(i).getTime().getSecond() << std::endl;
        

        std::cout << "===== Request & Status =====" << std::endl;
        out << "Request: " << entries.at(i).getRequest() << std::endl;
        out << "Status: " << entries.at(i).getStatus() << std::endl;


        std::cout << "========== Bytes ==========" << std::endl;
        out << "Bytes: " << entries.at(i).getBytes() << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;
    }
}


// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& entries) {
    int entrySize = entries.size();

    for (int i = 0; i < entrySize; i++) {
        out << "Host: " << entries.at(i).getHost() << std::endl;
    }
}


// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& entries) {

    int totalByte = 0;

    for (int i = 0; i < int(entries.size() - 1); i++) {
        totalByte += entries.at(i).getBytes();
    }

    return totalByte;
}

/*
void uniqueIp() {
    std::unordered_map<String, int> myMap;

    loop over hosts:
        ++myMap[host]; // host = IP
    
    for () : myMap {

    }
}
*/