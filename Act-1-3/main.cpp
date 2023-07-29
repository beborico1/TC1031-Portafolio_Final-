/** 
* Ayetza Yunnuen Infante García  A01709011
* Luis Carlos Rico Almada  A01252831

* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include <ctime>
#include "Registro.h"
#include "Bitacora.h"

// Función para convertir la fecha proporcionada por el usuario a time_t
time_t fechaUsuarioATimeT(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo) {
  struct tm tm = {0};
  std::string fechaStr = dia + " " + mes + " 2023 " + hora + ":" + minuto + ":" + segundo;
  strptime(fechaStr.c_str(), "%d %b %Y %H:%M:%S", &tm);
  time_t t = mktime(&tm);
  return t;
}

int main() {
  // Crear un objeto de la clase Bitacora
  Bitacora bitacora;
  std::vector<std::string> archivos = {"TestCases/test01.txt", "TestCases/test02.txt", "TestCases/test03.txt"};

  // Leer los registros del archivo bitacora.txt
  try {
    bitacora.leerArchivo("bitacora.txt");
  } catch(const std::invalid_argument& e) {
    std::cerr << "Error al leer el archivo: " << e.what() << '\n';
    return 1; // terminar el programa si no se puede leer el archivo
  }
  
  // Crear objetos de la clase Registro (un renglon de la bitacora)
  Registro a("Jan", "01", "00", "01", "02", "1.1.1.1", "123", "Falla 1");
  Registro b("Feb", "04", "00", "01", "02", "1.1.1.3", "1234", "Falla 2");
  Registro c("Dec", "01", "00", "01", "02", "1.1.1.1", "123", "Falla 1");

  std::cout << a.getAll() << std::endl;
  std::cout << "a: " << a.getFechaHora() << std::endl;
  std::cout << b.getAll() << std::endl;
  std::cout << "b: " << b.getFechaHora() << std::endl;
  std::cout << c.getAll() << std::endl;
  std::cout << "c: " << c.getFechaHora() << std::endl;
  
  if (a > b) 
    std::cout << "a mayor b" << std::endl;
  else
    std::cout << "a menor b" << std::endl;

  if (c > a) 
    std::cout << "c mayor a" << std::endl;
  else
    std::cout << "c menor a" << std::endl;

  // Agregar registros a la bitacora
  bitacora.agregarRegistro(a);
  bitacora.agregarRegistro(b);
  bitacora.agregarRegistro(c);

  // Ordenar los registros
  bitacora.ordenarRegistros();

  // Solicitar fechas de inicio y fin al usuario
  std::string mesInicio, diaInicio, horaInicio, minutoInicio, segundoInicio;
  std::string mesFin, diaFin, horaFin, minutoFin, segundoFin;

  std::cout << "Introduzca la fecha de inicio (en formato MM DD HH mm ss): ";
  std::cin >> mesInicio >> diaInicio >> horaInicio >> minutoInicio >> segundoInicio;
  time_t fechaInicio = fechaUsuarioATimeT(mesInicio, diaInicio, horaInicio, minutoInicio, segundoInicio);

  std::cout << "Introduzca la fecha de fin (en formato MM DD HH mm ss): ";
  std::cin >> mesFin >> diaFin >> horaFin >> minutoFin >> segundoFin;
  time_t fechaFin = fechaUsuarioATimeT(mesFin, diaFin, horaFin, minutoFin, segundoFin);

  // Imprimir registros en un rango proporcionado por el usuario
  bitacora.imprimirRango(fechaInicio, fechaFin);

  // Escribir los registros a un archivo
  bitacora.escribirArchivo("bitacora_ordenada.txt");

  return 0;
}