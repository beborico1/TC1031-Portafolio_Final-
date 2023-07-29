#ifndef STRINGEQUALITY_H
#define STRINGEQUALITY_H

#include <string>

class StringEquality {
public:
    bool operator()(const std::string& ip1, const std::string& ip2) const {
        return ip1 == ip2;
    }
};

#endif  // STRINGEQUALITY_H
