/** 
* Fecha 23 de Julio, 2023
* Autores: Luis Carlos Rico Almada - A01252831
* Ayetza Yunnuen Infante García - A01709011
**/

#include "Registro.h"

Registro::Registro() {
  mes = "";
  dia = "";
  horas = "";
  minutos = "";
  segundos = "";
  ip = "";
  puerto = "";
  falla = "";
  fechaHora = 0;
  ipDecimal = 0;
}

Registro::Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla) {
    mes = _mes;
    dia = _dia;
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
    ip = _ip;
    puerto = _puerto;
    falla = _falla;
    // Convertir a Linux timestamp
    dateStruct.tm_hour = std::stoi(horas);
    dateStruct.tm_min = std::stoi(minutos);
    dateStruct.tm_sec = std::stoi(segundos);
    dateStruct.tm_mday = std::stoi(dia);
    // resuelve problemas de compatibilidad con Windows
    dateStruct.tm_isdst = 0;
    for (int i = 0; i < (int)meses.size(); i++) {
      if (meses[i] == mes)
        dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2023 - 1900; // asumimos el año 2023
    // Obtener el Linux timestamp
    // https://cplusplus.com/reference/ctime/mktime/
    fechaHora = mktime(&dateStruct);
    // Conversion de la ip a numero decimal
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;
    while (posFound >= 0) {
      posFound = ip.find(".", posInit);
      splitted = ip.substr(posInit, posFound-posInit);
      posInit = posFound + 1;
      results.push_back(splitted);
    } 
    int oct3 = std::stoi(results[0]);
    int oct2 = std::stoi(results[1]);
    int oct1 = std::stoi(results[2]);
    int oct0 = std::stoi(results[3]);
    ipDecimal = (oct3*std::pow(256,3)) + (oct2*std::pow(256,2)) + (oct1*256) + oct0;
}

std::string Registro::getAll() {
  return mes + " " + dia + " " + horas + ":" + minutos + ":" + segundos + " " + ip + ":" + puerto + " " + falla;  
}

// sobrecarga de operadores de comparacion
bool Registro::operator ==(const Registro &other) const {
  return this->ipDecimal == other.ipDecimal;
}

bool Registro::operator !=(const Registro &other) const {
  return this->ipDecimal != other.ipDecimal;
}

bool Registro::operator>(const Registro& r) const {
    return second > r.second;
}
bool Registro::operator<(const Registro& r) const {
    return second < r.second;
}

bool Registro::operator >=(const Registro &other) const{
  return this->ipDecimal >= other.ipDecimal;
}

bool Registro::operator <=(const Registro &other) const{
  return this->ipDecimal <= other.ipDecimal;
}

std::string Registro::getIP() const {
    return ip;
}

std::string Registro::getAll() const {
    return mes + " " + dia + " " + horas + ":" + minutos + ":" + segundos + " " + ip + ":" + puerto + " " + falla;  
}
