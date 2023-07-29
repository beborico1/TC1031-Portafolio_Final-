/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Registro.h:
        Declaración de la clase Registro
*/

#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "Fecha.h"

class Registro {

  private:
    Fecha fecha;
    std::string ip, puerto, falla;

  public:
    Registro();
    Registro(Fecha _fecha, std::string _ip, std::string _puerto, std::string _falla);

    std::string getAll() const;
    void writeAll(std::ostream& os) const;
    time_t getFechaHora();
    // sobrecarga de operadores de comparacion
    bool operator ==(const Registro &other) const;
    bool operator !=(const Registro &other) const;
    bool operator  >(const Registro &other) const;
    bool operator  <(const Registro &other) const;
    bool operator >=(const Registro &other) const;
    bool operator <=(const Registro &other) const;
    Registro& operator=(const Registro& other);
    // sobrecarga operador << 
    friend std::ostream& operator<<(std::ostream& os, const Registro& reg);
};

#endif  // _REGISTRO_H_
