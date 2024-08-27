//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//

#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>
#include <map>


class Date {
public:
    Date() {};

    //////////////////////// ADDED ////////////////////////
    String getDay() const { return this->day; };
    String getMonth() const { return this->month; };
    String getYear() const { return this->year; };

    void setDate(String d, String m, String y) {
        this->day = d;
        this->month = m;
        this->year = y;
    }
    ///////////////////////////////////////////////////////

private:
    String day, month, year;
};

//
class Time {
  public:
    Time() {};

    //////////////////////// ADDED ////////////////////////
    String getHour() const { return this->hour; };
    String getMinute () const { return this->minute; };
    String getSecond() const { return this->second; };

    void setTime(String h, String m, String s) {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    ///////////////////////////////////////////////////////

  private:
    String hour, minute, second;
};


// A single log entry
class LogEntry {
public:
    LogEntry() {};
    LogEntry(const String&);

    friend std::ostream& operator<<(std::ostream&, const LogEntry&);
    

    //////////////////////// ADDED ////////////////////////
    Date getDate() const { return this->date; };
    Time getTime() const { return this->time; };

    String getHost() const { return this->host; };
    String getRequest() const { return this->request; };
    String getStatus() const { return this->status; };
    int getBytes() const { return this->number_of_bytes; };
    ///////////////////////////////////////////////////////


private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//
std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);


//void ip_address (std::ostream&, const std::vector<LogEntry>);
//std::map<String, int>;

/*
void uniqueIp() {
    std::unordered_map<String, int> myMap;

    loop over hosts:
        ++myMap[host]; // host = IP

}
*/


#endif
