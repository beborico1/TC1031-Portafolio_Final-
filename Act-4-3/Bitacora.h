#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <utility>
#include <limits>

#include "Registro.h"


class Bitacora {
  private:
    std::vector<Registro> listaRegistros;
    std::priority_queue<std::pair<int, std::string>> pq;
    std::string bootMaster;

  public:
    Bitacora(); // Complejidad computacional: O(1)
    ~Bitacora(); // Complejidad computacional: O(1)
    void leerArchivo(const std::string& filename, std::map<std::string, std::vector<Registro>>& adjList); // Complejidad computacional: O(n)
    void gradoSalida(std::map<std::string, std::vector<Registro>>& adjList); // Complejidad computacional: O(n)
    void mayorGradoSalida(); // Complejidad computacional: O(1)
    std::string obtenerBootMaster(); // Complejidad computacional: O(1)
    std::map<std::string, int> dijkstra(const std::map<std::string, std::vector<Registro>>& adjList, const std::string& src); // Complejidad computacional: O(n^2)
    void guardarDistanciasYObtenerIPMasLejana(const std::map<std::string, int>& distancias); // Complejidad computacional: O(n)
    
};


#endif  // _BITACORA_H_
