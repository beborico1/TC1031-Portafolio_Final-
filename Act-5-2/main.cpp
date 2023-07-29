
/**
 * Ejemplo que implementa objetos de la clase Registro
 * que contienen una fecha-hora convertida a Linux timestamp
 * para realizar comparaciones (sobrecarga de operadores)
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include "HashTable.h"
#include "IPInfo.h"
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  Bitacora bitacora;
  HashTable hashTable(997); // Crea una tabla hash de tamaño 997
  bitacora.leerArchivo(
      hashTable,
      "bitacoraGrafos.txt"); // Lee y almacena los datos de la bitácora

  std::cout << "Número total de colisiones: " << hashTable.getCollisionCount()
            << "\n";

  // Solicita una IP al usuario y muestra su resumen
  std::string ip;
  std::cout << "Ingrese una IP para obtener su resumen: ";
  std::cin >> ip;
  hashTable.getIPSummary(hashTable, ip);

  return 0;
}
