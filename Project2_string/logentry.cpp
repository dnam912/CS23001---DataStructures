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


// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& rhs) { // Copy const
    // 1. Copy the value from file by &rhs
    // 2. Seperate strings by parse()
    // 3. get value from vector[i]

    String lhs(rhs);
    std::vector<String> stringEntries = lhs.split(' ');

    if (stringEntries.size() == 10) {
        this->host = stringEntries[0];                        // Host

        this->date.setDate( stringEntries[3].substr(1,2),     // Day
                            stringEntries[3].substr(4,6),     // Month
                            stringEntries[3].substr(8,11) );  // Year

        this->time.setTime( stringEntries[3].substr(13,14),   // Hour
                            stringEntries[3].substr(16,17),   // Minute
                            stringEntries[3].substr(19,20) ); // Second

        int requestLength = stringEntries[5].length();        // Request
        this->request = stringEntries[5].substr(1, requestLength);
        this->request += String(" ");
        this->request += stringEntries[6];                    // GET /~darci/

        this->status = stringEntries[8];                      // Status

        if (stringEntries[9] == '-') {
            this->number_of_bytes = 0;                        // Bytes
        } else {
            int bytesLength = stringEntries[9].length();
            String bytes = stringEntries[9].substr(0, bytesLength);
            this->number_of_bytes = convertFromStringToInt(bytes);
        }
    }
    else if (stringEntries.size() < 10) {
        std::cout << "stringEntries.size() is less than 10." << std::endl;
    }
    else if (stringEntries.size() > 10) {
        std::cout << "stringEntries.size() is bigger than 10." << std::endl;
    }
}


std::ostream& operator<<(std::ostream& out, const LogEntry& logEntry) {
    
    out << logEntry;

    return out;
}


// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {

    std::vector<LogEntry> linesOfLogEntry;
    
    // getline() is unstable. 
    // ==================== getline() ==================== //
    // int maxSize = 200;
    // char temp[200];
    // int lineNumber = 1;
    // while (!in.eof()) { // read the whole line
    //     in.getline(temp, maxSize); // include reading whitespaces
    //     std::cout << "Line Number: " << lineNumber << std::endl;
    //     lineNumber++;
    //     if (lineNumber == 10000) {
    //         break;
    //     }
    //     LogEntry stringsOfLogEntry(temp);
    //     linesOfLogEntry.push_back(stringsOfLogEntry);
    // }


    // ==================== get() ==================== //
    char ch;
    in.get(ch);
    String str_line;

    while (!in.eof()) { 
        if (ch != '\n') {
            str_line += ch;
        } else {
            linesOfLogEntry.push_back(str_line);
            str_line = String();
        }
        in.get(ch);
    }

    return linesOfLogEntry;
}


// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& entries) {
    // Print all the logEntry entries (neatly one per line).
    int entrySize = int(entries.size());
    std::cout << "Size of vector<LogEntry>: " << entrySize << std::endl;

    for (int i = 0; i < entrySize; i++) {
        std::cout << "[ LogEntry: " << (i+1) << " ]" << std::endl;
        std::cout << "==============================" << std::endl;
        //std::cout << "========== Host ==========" << std::endl;
        out << "Host: " << entries[i].getHost() << std::endl;


        //std::cout << "========== Date ==========" << std::endl;
        out << "Year: " << entries[i].getDate().getYear() << std::endl;
        out << "Month: " << entries[i].getDate().getMonth() << std::endl;
        out << "Day: " << entries[i].getDate().getDay() << std::endl;


        //std::cout << "========== Time ==========" << std::endl;
        out << "Hour: " << entries[i].getTime().getHour() << std::endl;
        out << "Minute: " << entries[i].getTime().getMinute() << std::endl;
        out << "Second: " << entries[i].getTime().getSecond() << std::endl;
        

        //std::cout << "===== Request & Status =====" << std::endl;
        out << "Request: " << entries[i].getRequest() << std::endl;
        out << "Status: " << entries[i].getStatus() << std::endl;


        //std::cout << "========== Bytes ==========" << std::endl;
        out << "Bytes: " << entries[i].getBytes() << std::endl;

        //std::cout << std::endl;
        std::cout << std::endl;
    }

    // uniqueIp(entries);
}


// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& entries) {

    for (int i = 0; i < int(entries.size()); i++) {
        out << "Host: " << entries[i].getHost() << std::endl;
    }
}


// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& entries) {

    int totalByte = 0;

    for (int i = 0; i < int(entries.size()); i++) {
        totalByte += entries[i].getBytes();
    }

    return totalByte;
}


// void uniqueIp(const std::vector<LogEntry>& entries) {
//     int entrySize = int(entries.size());

//     std::unordered_map<String, int> myMap;
//     for (int i = 0; entrySize; ++i) {
//         String host = entries[i].getHost();
//         std::cin >> host;
//         ++myMap[host]; // host = IP
//     }

//     for (auto &i : myMap) {
//         std::cout << "Host: " << i.first << "|" << i.second << std::endl;
//     }

//     // std::unordered_map<String, int>:: iterator i;
//     // for (i = myMap.begin(); i != myMap.end(); ++i) {
//     //     std::cout << "Host: " << i->first << "|" << i->second << std::endl;
//     // }
// }


/*    
    if(myMap.find(host) == myMap.end()) {
            myMap.insert(make_pair(host, 1));
        }
        else {
            ++myMap[host]; // host = IP
        }

    for(auto it = myMap.begin(); it != myMap();) {
        if (!(*it).first >= &&) {
            it = myMap.erase(it);
        } else {
            ++it;
        }
    }

    for (auto &i : myMap) {
        std::cout << "Host: " << i.first << "|" << i.second << std::endl;
    }
}

    loop over hosts:
        ++myMap[host]; // host = IP
    
*/