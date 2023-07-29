/** 
* Act 3.3 - Actividad Integral de BST (Evidencia Competencia)
* Este programa en C++ procesa y analiza registros de bitácora. Lee los registros de un archivo, los ordena por IP, los escribe en un nuevo archivo, y luego identifica y registra las diez IPs con mayor número de accesos.
* Fecha 23 de Julio, 2023
* Autores: Luis Carlos Rico Almada - A01252831
* Ayetza Yunnuen Infante García - A01709011
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

int main() {
    Bitacora bitacora;
    
    bitacora.leerArchivo("bitacoraHeap.txt");
    bitacora.heapSort();
    bitacora.escribeBitacoraOrdenada("bitacora_ordenada.txt");
    bitacora.top10IPs("ips_con_mayor_acceso.txt");

    return 0;
}
