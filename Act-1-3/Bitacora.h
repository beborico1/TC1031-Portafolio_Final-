/** 
* Ayetza Yunnuen Infante García  A01709011
* Luis Carlos Rico Almada  A01252831
**/

#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Registro.h"

class Bitacora {
  private:
    std::vector<Registro> listaRegistros;
    int numComparisons;  // Agrega esta línea
    int numSwaps;        // Agrega esta línea

  public:
    Bitacora();
    ~Bitacora();
    void leerArchivo(std::string filePath);
    void leerArchivoTest(std::string filePath);
    void bubbleSort();    
    void quickSort(int low, int high);
    int particionar(int low, int high);
    void ordenarRegistros();
    int busquedaBinaria(time_t fecha);
    void imprimirRango(time_t fechaInicio, time_t fechaFin);
    void escribirArchivo(std::string filePath);
    void agregarRegistro(Registro registro);
};


#endif  // _BITACORA_H_
