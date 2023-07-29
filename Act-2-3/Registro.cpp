/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Registro.cpp:
        Implementación de la clase Registro
*/

#include "Registro.h"
#include "Fecha.h"

Registro::Registro() : fecha("Jan 01 00:00:00"), ip(""), puerto(""), falla("") {

  std::cout << "Se llamo el inicializador default" << std::endl;
}

Registro::Registro(Fecha _fecha, std::string _ip, std::string _puerto, std::string _falla) {
    fecha = _fecha;
    ip = _ip;
    puerto = _puerto;
    falla = _falla;
}

void Registro::writeAll(std::ostream& os) const {
  try {
    std::string fechaStr = fecha.toString();
    if (!fechaStr.empty()) {
      os << fechaStr << " ";
    } else {
      throw std::runtime_error("Error: Fecha no inicializada");
    }
    
    if (!ip.empty()) {
      os << ip << " ";
    } else {
      throw std::runtime_error("Error: IP no inicializada");
    }
    
    if (!puerto.empty()) {
      os << puerto << " ";
    } else {
      throw std::runtime_error("Error: Puerto no inicializado");
    }
    
    if (!falla.empty()) {
      os << falla;
    } else {
      throw std::runtime_error("Error: Falla no inicializada");
    }
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Error de asignación de memoria: " << e.what() << '\n';
    throw;
  }
  catch (const std::exception& e) {
    std::cerr << "Excepción capturada: " << e.what() << '\n';
    throw;
  }
}


std::string Registro::getAll() const{
  std::string result;
  
  if (!ip.empty()) {
    //std::cout << "IP: " << ip << std::endl;
    result += ip + ":";
  } else {
    return "Error: IP no inicializada";
  }
  
  if (!puerto.empty()) {
    //std::cout << "Puerto: " << puerto << std::endl;
    result += puerto + " ";
  } else {
    return "Error: Puerto no inicializado";
  }
  
  if (!falla.empty()) {
    //std::cout << "Falla: " << falla << std::endl;
    result += falla + " ";
  } else {
    return "Error: Falla no inicializada";
  }
  
  std::string fechaStr = fecha.toString();
  if (!fechaStr.empty()) {
    //std::cout << "Fecha: " << fechaStr << std::endl;
    result += fechaStr;
  } else {
    return "Error: Fecha no inicializada";
  }
  
  return result;  
}

time_t Registro::getFechaHora() {
  //std::cout << "GetFechaHora: " << fecha.getTimestamp() << std::endl;
  return fecha.getTimestamp();
}

// sobrecarga de operadores de comparacion
bool Registro::operator ==(const Registro &other) const {
  return this->fecha.getTimestamp() == other.fecha.getTimestamp();
}

bool Registro::operator !=(const Registro &other) const {
  return this->fecha.getTimestamp() != other.fecha.getTimestamp();
}

bool Registro::operator  >(const Registro &other) const {
  return this->fecha.getTimestamp() > other.fecha.getTimestamp();
}

bool Registro::operator  <(const Registro &other) const{
  return this->fecha.getTimestamp() < other.fecha.getTimestamp();
}

bool Registro::operator >=(const Registro &other) const{
  return this->fecha.getTimestamp() >= other.fecha.getTimestamp();
}

bool Registro::operator <=(const Registro &other) const{
  return this->fecha.getTimestamp() <= other.fecha.getTimestamp();
}

Registro& Registro::operator=(const Registro& other) {
    if (this != &other) {
        // asumimos que la clase Fecha tiene un operador de asignación adecuado
        fecha = other.fecha;
        ip = other.ip;
        puerto = other.puerto;
        falla = other.falla;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Registro &reg) {
  os << reg.getAll();
  return os;
}
