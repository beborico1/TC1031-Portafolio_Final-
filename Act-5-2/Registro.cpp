#include "Registro.h"

Registro::Registro() : dia(0), peso(0) {} // Complejidad computacional: O(1)

Registro::Registro(std::string _mes, int _dia, std::string _hora, std::string _ipOrigen, std::string _ipDestino, int _peso, std::string _razon)
    : mes(_mes), dia(_dia), hora(_hora), ipOrigen(_ipOrigen), ipDestino(_ipDestino), peso(_peso), razon(_razon) {} // Complejidad computacional: O(1)

// Ref: https://www.cplusplus.com/reference/string/to_string/
std::string Registro::getAll() { // Complejidad computacional: O(1)
    return mes + " " + std::to_string(dia) + " " + hora + " " + ipOrigen + " " + ipDestino + " " + std::to_string(peso) + " " + razon;
}

// Ref: https://www.geeksforgeeks.org/operator-overloading-c/
bool Registro::operator ==(const Registro &other) const { // Complejidad computacional: O(1)
    return peso == other.peso;
}

bool Registro::operator !=(const Registro &other) const { // Complejidad computacional: O(1)
    return peso != other.peso;
}

bool Registro::operator >(const Registro &other) const { // Complejidad computacional: O(1)
    return peso > other.peso;
}

bool Registro::operator <(const Registro &other) const { // Complejidad computacional: O(1)
    return peso < other.peso;
}

bool Registro::operator >=(const Registro &other) const { // Complejidad computacional: O(1)
    return peso >= other.peso;
}

bool Registro::operator <=(const Registro &other) const { // Complejidad computacional: O(1)
    return peso <= other.peso;
}

// Ref: https://www.geeksforgeeks.org/getter-and-setter-in-c/
std::string Registro::getMes() const { // Complejidad computacional: O(1)
    return mes;
}

void Registro::setMes(std::string _mes) { // Complejidad computacional: O(1)
    mes = _mes;
}

int Registro::getDia() const { // Complejidad computacional: O(1)
    return dia;
}

void Registro::setDia(int _dia) { // Complejidad computacional: O(1)
    dia = _dia;
}

std::string Registro::getHora() const { // Complejidad computacional: O(1)
    return hora;
}

void Registro::setHora(std::string _hora) { // Complejidad computacional: O(1)
    hora = _hora;
}

std::string Registro::getIpOrigen() const { // Complejidad computacional: O(1)
    return ipOrigen;
}

void Registro::setIpOrigen(std::string _ipOrigen) { // Complejidad computacional: O(1)
    ipOrigen = _ipOrigen;
}

std::string Registro::getIpDestino() const { // Complejidad computacional: O(1)
    return ipDestino;
}

void Registro::setIpDestino(std::string _ipDestino) { // Complejidad computacional: O(1)
    ipDestino = _ipDestino;
}

int Registro::getPeso() const { // Complejidad computacional: O(1)
    return peso;
}

void Registro::setPeso(int _peso) { // Complejidad computacional: O(1)
    peso = _peso;
}

std::string Registro::getRazon() const { // Complejidad computacional: O(1)
    return razon;
}

void Registro::setRazon(std::string _razon) { // Complejidad computacional: O(1)
    razon = _razon;
}