/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Fecha.cpp:
        Implementación de la clase Fecha
*/

#include "Fecha.h"
#include <sstream>
#include <ctime>
#include <iomanip>
#include <iostream>

Fecha::Fecha(std::string fechaStr) {
  meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  std::istringstream fechaStream(fechaStr);
  std::string mesStr, diaStr, tiempoStr;
  fechaStream >> mesStr >> diaStr >> tiempoStr;

  std::istringstream tiempoStream(tiempoStr);
  std::string horaStr, minutoStr, segundoStr;
  getline(tiempoStream, horaStr, ':');
  getline(tiempoStream, minutoStr, ':');
  getline(tiempoStream, segundoStr, ':');

  struct tm tmFecha = {0};
  tmFecha.tm_hour = std::stoi(horaStr);
  tmFecha.tm_min = std::stoi(minutoStr);
  tmFecha.tm_sec = std::stoi(segundoStr);
  tmFecha.tm_mday = std::stoi(diaStr);
  tmFecha.tm_isdst = -1; // -1 significa que la biblioteca debe averiguar si DST está en efecto

  for (int i = 0; i < (int)meses.size(); i++) {
    if (meses[i] == mesStr)
      tmFecha.tm_mon = i;
  }

  tmFecha.tm_year = 2023 - 1900; // asumimos el año 2023
  fecha = mktime(&tmFecha);
}

time_t Fecha::getTimestamp() const {
  //std::cout << "getTimestamp: " << fecha << std::endl;
  return fecha;
}

std::string Fecha::toString() const {
  //std::cout << "Fecha1: " << fecha << std::endl;
  struct tm * tmFecha = localtime(&fecha); 
  //std::cout << "Fecha2: " << tmFecha->tm_year << std::endl;
  std::ostringstream fechaStream;
  //std::cout << "Fecha3: " << fechaStream.str() << std::endl;
  fechaStream << std::put_time(tmFecha, "%b %d %H:%M:%S");
  //std::cout << "Fecha4: " << fechaStream.str() << std::endl;
  return fechaStream.str();
}