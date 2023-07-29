#ifndef IPHASHFUNCTION_H
#define IPHASHFUNCTION_H

#include <sstream>
#include <string>

class IPHashFunction {
public:
    std::size_t operator()(const std::string& ip) const {
        std::stringstream ss(ip);
        int a, b, c, d;  // los cuatro octetos de la IP
        char ch;  // para el '.'
        ss >> a >> ch >> b >> ch >> c >> ch >> d;
        return ((a << 24) | (b << 16) | (c << 8) | d);
    }
};

#endif  // IPHASHFUNCTION_H
