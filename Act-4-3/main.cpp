
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

#include <iostream>
#include "Bitacora.h"

int main() { // Complejidad computacional: O(n)
    std::map<std::string, std::vector<Registro>> adjList;
    Bitacora bitacora;
    
    bitacora.leerArchivo("bitacoraGrafos.txt", adjList);
    bitacora.gradoSalida(adjList);
    bitacora.mayorGradoSalida();

    std::string bootMaster = bitacora.obtenerBootMaster();
    if (!bootMaster.empty()) {
        auto distancias = bitacora.dijkstra(adjList, bootMaster);
        bitacora.guardarDistanciasYObtenerIPMasLejana(distancias);
    }
  
    return 0;
}
