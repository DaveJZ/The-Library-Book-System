#include "Date.h"
#include <ctime>

std::string Date::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
}

std::string Date::getDueDate(int daysToAdd) {
    time_t now = time(0);
    now += (daysToAdd * 24 * 60 * 60);
    tm* ltm = localtime(&now);
    return std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
}