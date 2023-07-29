/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Bitacora.h:
        Declaración de la clase Bitacora
*/

#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Registro.h"
#include "DoublyLinkedList.h"

class Bitacora {
  private:
    DoublyLinkedList<Registro> listaRegistros;
    int numComparisons;
    int numSwaps;

  public:
    Bitacora(); // Complejidad computacional: O(1)
    ~Bitacora(); // Complejidad computacional: O(1)
    std::string clean_string(const std::string& input); // Complejidad computacional: O(n)
    void leerArchivo(std::string filePath); // Complejidad computacional: O(n)
    void bubbleSort();     // Complejidad computacional: O(n^2)
    void quickSort(int low, int high); // Complejidad computacional: O(n log n)
    int particionar(int low, int high); // Complejidad computacional: O(n)
    void ordenarRegistros(); // Complejidad computacional: O(n^2)
    int busquedaBinaria(time_t fecha); // Complejidad computacional: O(log n)
    void imprimirRango(time_t fechaInicio, time_t fechaFin); // Complejidad computacional: O(n)
    void escribirArchivo(std::string filePath); // Complejidad computacional: O(n)
    void agregarRegistro(Registro registro); // Complejidad computacional: O(1)
    bool isListaOrdenada() const;
};


#endif  // _BITACORA_H_
