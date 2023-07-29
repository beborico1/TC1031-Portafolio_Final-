/** 
* Fecha 23 de Julio, 2023
* Autores: Luis Carlos Rico Almada 
* A01252831, Ayetza Yunnuen Infante García - A01709011
**/

#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue> // para std::priority_queue
#include <utility> // para std::pair

#include "Registro.h"


class Bitacora {
  private:
    std::vector<Registro> listaRegistros;

  public:
    Bitacora();
    ~Bitacora();
    void leerArchivo(std::string filePath);
    void heapSort();
    void escribeBitacoraOrdenada(std::string nombreArchivo);
    void cuentaVisitasPorIP(std::priority_queue<std::pair<int, std::string>>& visitasPorIP);
    void top10IPs(std::string nombreArchivo);
    void heapify(std::vector<Registro> &A, int n, int k, unsigned int &compara, unsigned int &swap);
    void sort_heap(std::vector<Registro> &A, int n, unsigned int &compara, unsigned int &swap);
    

};


#endif  // _BITACORA_H_
