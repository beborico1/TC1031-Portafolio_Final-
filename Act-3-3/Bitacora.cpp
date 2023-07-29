/** 
* Fecha 23 de Julio, 2023
* Autores: Luis Carlos Rico Almada 
* A01252831, Ayetza Yunnuen Infante García - A01709011
**/

#include "Bitacora.h"

std::priority_queue<std::pair<int, std::string>> visitasPorIP;

Bitacora::Bitacora() {
  listaRegistros.clear();
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}
      
// https://cplusplus.com/reference/fstream/ifstream/
void Bitacora::leerArchivo(std::string filePath) {
  std::string month, day, hours, minutes, seconds, ipAdd, port, error;
  //int dia, puerto;
  int numRecords = 0; 
  std::ifstream file(filePath);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while (!file.eof()) {
        std::getline(file, month, ' ');
        std::getline(file, day, ' ');
        std::getline(file, hours, ':');
        std::getline(file, minutes, ':');
        std::getline(file, seconds, ' ');
        std::getline(file, ipAdd, ':');
        std::getline(file, port, ' ');
        std::getline(file, error);
        numRecords ++;
        // crear un objeto de la clase Registro
        Registro tmpRec(month, day, hours, minutes, seconds, ipAdd, port, error);
        listaRegistros.push_back(tmpRec);       
    }
    file.close();
  } 
}

void Bitacora::cuentaVisitasPorIP(std::priority_queue<std::pair<int, std::string>>& visitasPorIP) {
    std::map<std::string, int> countMap;
    for (const auto& registro : listaRegistros) {
        countMap[registro.getIP()]++;
    }
    for (const auto& pair : countMap) {
        visitasPorIP.push({pair.second, pair.first});
    }
}

void Bitacora::top10IPs(std::string nombreArchivo) {
    std::priority_queue<std::pair<int, std::string>> visitasPorIP;
    cuentaVisitasPorIP(visitasPorIP);
  
    std::ofstream archivo(nombreArchivo);
    int rank = 1;
    while (!visitasPorIP.empty() && rank <= 10) {
        auto top = visitasPorIP.top();
        visitasPorIP.pop();
        archivo << "(Top " << rank << ") " << top.second << " se encontro " << top.first << " veces." << '\n';
        std::cout << "(Top " << rank << ") " << top.second << " se encontro " << top.first << " veces." << '\n';
        rank++;  // incrementa rank aquí
    }
}

void Bitacora::escribeBitacoraOrdenada(std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    for (const auto& registro : listaRegistros) {
        archivo << registro.getAll() << '\n';
    }
}

void Bitacora::heapSort() {
    unsigned int compara = 0;
    unsigned int swap = 0;
    int n = listaRegistros.size();
    
    for (int i = n/2-1; i >= 0; i--) {
        heapify(listaRegistros, n, i, compara, swap);
    }
  
    sort_heap(listaRegistros, n, compara, swap);
}

void Bitacora::heapify(std::vector<Registro> &A, int n, int k, unsigned int &compara, unsigned int &swap) {
  int largest = k;
  int left = 2*k + 1;
  int right = 2*k + 2;

  // Si el hijo izquierdo es mayor que la raiz
  if (left < n && A[left] > A[largest])
    largest = left;

  // Si el hijo derecho es mayor que hasta ahora el mayor
  if (right < n && A[right] > A[largest])
    largest = right;

  compara+=2;

  // Si el más grande no es la raíz
  if (largest != k) {
    std::swap(A[k], A[largest]);
    swap++;
    heapify(A, n, largest, compara, swap);
  }
}

void Bitacora::sort_heap(std::vector<Registro> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  // 1. Construir el Heap a partir de la lista 
  for (int i = n/2-1; i >= 0; i--) {
    heapify(A, n, i, compara, swap);
  }
  // 2. Extraer elemento por elemento del heap
  for (int i = n-1; i > 0; i--) {
    // intercambiar raiz con la ultima hoja
    std::swap(A[0], A[i]);
    swap++;
    heapify(A, i, 0, compara, swap);
  }
}