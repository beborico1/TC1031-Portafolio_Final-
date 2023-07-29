#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime>

class Registro {
private:
    std::string mes;
    int dia;
    std::string hora;
    std::string ipOrigen;
    std::string ipDestino;
    int peso;
    std::string razon;
public:
    Registro(); // Complejidad computacional: O(1)
    Registro(std::string _mes, int _dia, std::string _hora, std::string _ipOrigen, std::string _ipDestino, int _peso, std::string _razon); // Complejidad computacional: O(1)
    
    std::string getMes() const; // Complejidad computacional: O(1)
    void setMes(std::string _mes); // Complejidad computacional: O(1)

    int getDia() const; // Complejidad computacional: O(1)
    void setDia(int _dia); // Complejidad computacional: O(1)

    std::string getHora() const; // Complejidad computacional: O(1)
    void setHora(std::string _hora); // Complejidad computacional: O(1)

    std::string getIpOrigen() const; // Complejidad computacional: O(1)
    void setIpOrigen(std::string _ipOrigen); // Complejidad computacional: O(1)

    std::string getIpDestino() const; // Complejidad computacional: O(1)
    void setIpDestino(std::string _ipDestino); // Complejidad computacional: O(1)

    int getPeso() const; // Complejidad computacional: O(1)
    void setPeso(int _peso); // Complejidad computacional: O(1)

    std::string getRazon() const; // Complejidad computacional: O(1)
    void setRazon(std::string _razon); // Complejidad computacional: O(1)

    std::string getAll(); // Complejidad computacional: O(1)

    // sobrecarga de operadores de comparacion
    bool operator ==(const Registro &other) const; // Complejidad computacional: O(1)
    bool operator !=(const Registro &other) const; // Complejidad computacional: O(1)
    bool operator  >(const Registro &other) const; // Complejidad computacional: O(1)
    bool operator  <(const Registro &other) const; // Complejidad computacional: O(1)
    bool operator >=(const Registro &other) const; // Complejidad computacional: O(1)
    bool operator <=(const Registro &other) const; // Complejidad computacional: O(1)
};

#endif  // _REGISTRO_H_
