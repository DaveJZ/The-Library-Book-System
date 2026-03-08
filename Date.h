#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
public:
    static std::string getCurrentDate();
    static std::string getDueDate(int daysToAdd);
};

#endif