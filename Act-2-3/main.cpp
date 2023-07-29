/* 
    Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

    Descripción:
        Practicar el uso de estructuras de datos lineales vistas en clase para resolver un problema relacionado con la situación problema.
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Ejecucion:
        ./main
    Compilacion para debug:
      g++ -std=c++17 -Wall -o main main.cpp Registro.cpp Fecha.cpp Bitacora.cpp
    main.cpp: 
        Programa para probar la clase LinkedList
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Registro.h"
#include "Bitacora.h"
#include "Fecha.h"

int main() { // Complejidad computacional: O(n^2)
  // Crear un objeto de la clase Bitacora
  Bitacora bitacora;
  
  std::vector<std::string> archivos;
  archivos.push_back("TestCases/test01.txt");
  archivos.push_back("TestCases/test02.txt");
  archivos.push_back("TestCases/test03.txt");

  // Leer los registros del archivo bitacora.txt
  try {
    bitacora.leerArchivo("bitacora_test.txt"); // bitacora.txt tomaba mucho tiempo en ordenar los registros con el cambio de estructura de datos, se cambió por bitacora_test.txt
  } catch(const std::invalid_argument& e) {
    std::cerr << "Error al leer el archivo: " << e.what() << '\n';
    return 1; // terminar el programa si no se puede leer el archivo
  }

  // Ordenar los registros
  bitacora.ordenarRegistros();

  std::cout << "Introduzca la fecha de inicio (en formato 'MMM dd HH:mm:ss'): ";
  std::string fechaInicioStr;
  std::getline(std::cin, fechaInicioStr);
  Fecha fechaInicio(fechaInicioStr);

  std::cout << "Introduzca la fecha de fin (en formato 'MMM dd HH:mm:ss'): ";
  std::string fechaFinStr;
  std::getline(std::cin, fechaFinStr);
  Fecha fechaFin(fechaFinStr);

  //std::cout << "Fecha de inicio: " << fechaInicio.toString() << std::endl;
  //std::cout << "Fecha de fin: " << fechaFin.toString() << std::endl;

  time_t inicioTimestamp = fechaInicio.getTimestamp();
  time_t finTimestamp = fechaFin.getTimestamp();

  //std::cout << "Timestamp de inicio: " << inicioTimestamp << std::endl;
  //std::cout << "Timestamp de fin: " << finTimestamp << std::endl;

    
  // Leer los registros del archivo bitacora.txt
  try {
    bitacora.leerArchivo("bitacora_ordenada.txt"); // bitacora.txt tomaba mucho tiempo en ordenar los registros con el cambio de estructura de datos, se cambió por bitacora_test.txt
  } catch(const std::invalid_argument& e) {
    std::cerr << "Error al leer el archivo: " << e.what() << '\n';
    return 1; // terminar el programa si no se puede leer el archivo
  }


  // Imprimir registros en un rango proporcionado por el usuario
  bitacora.imprimirRango(inicioTimestamp, finTimestamp);

  //std::cout << "Ahora se escribirán los registros ordenados en un archivo" << std::endl;

  // Escribir los registros a un archivo
  //bitacora.escribirArchivo("bitacora_ordenada.txt");

  return 0;
}