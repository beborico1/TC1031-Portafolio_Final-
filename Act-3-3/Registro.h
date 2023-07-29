/** 
* Fecha 23 de Julio, 2023
* Autores: Luis Carlos Rico Almada - A01252831
* Ayetza Yunnuen Infante García - A01709011
**/

#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>

class Registro {

  private:
    std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    // https://cplusplus.com/reference/ctime/tm/
    struct tm dateStruct;
    // Linux timestamp (segundos transcurridos desde el 1 de enero de 1970)
    time_t fechaHora;
    // Conversion de la ip a un numero decimal
    unsigned int ipDecimal;

  public:
    Registro();
    Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla);
    std::string getAll() ;
    std::string first;
    int second;

    // sobrecarga de operadores de comparacion
    bool operator ==(const Registro &other) const;
    bool operator !=(const Registro &other) const;
    bool operator  >(const Registro &other) const;
    bool operator  <(const Registro &other) const;
    bool operator >=(const Registro &other) const;
    bool operator <=(const Registro &other) const;
    std::string getAll() const;
    std::string getIP() const;
};



#endif  // _REGISTRO_H_
