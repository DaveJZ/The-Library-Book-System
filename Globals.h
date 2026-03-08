#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };
enum class BookStatus { Available, CheckedOut };

inline std::string genreToString(Genre g) {
    switch (g) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "NonFiction";
        case Genre::Mystery: return "Mystery";
        case Genre::Science: return "Science";
        case Genre::Biography: return "Biography";
        default: return "Unknown";
    }
}

inline Genre stringToGenre(const std::string& s) {
    if (s == "NonFiction") return Genre::NonFiction;
    if (s == "Mystery") return Genre::Mystery;
    if (s == "Science") return Genre::Science;
    if (s == "Biography") return Genre::Biography;
    return Genre::Fiction;
}

inline std::string statusToString(BookStatus s) {
    return (s == BookStatus::Available) ? "Available" : "Checked Out";
}

#endif