/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Fecha.h:
        Declaración de la clase Fecha
*/


#ifndef _FECHA_H_
#define _FECHA_H_

#include <string>
#include <vector>

class Fecha {
private:
  std::vector<std::string> meses;
  time_t fecha;

public:
  Fecha() : fecha(0) { } // Constructor predeterminado
  Fecha(std::string fechaStr);

  time_t getTimestamp() const;
  std::string toString() const;
};

#endif  // _FECHA_H_