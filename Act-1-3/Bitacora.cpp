/** 
* Ayetza Yunnuen Infante García  A01709011
* Luis Carlos Rico Almada  A01252831
**/

#include "Bitacora.h"
#include <chrono>

Bitacora::Bitacora() : numComparisons(0), numSwaps(0) {
  // Constructor: Aquí puedes inicializar las variables miembro si es necesario.
}

Bitacora::~Bitacora() {
  // Destructor: Aquí puedes liberar los recursos si es necesario.
}

void Bitacora::leerArchivo(std::string filePath) {
  std::string month, day, hours, minutes, seconds, ipAdd, port, error;
  int puerto;
  int numRecords = 0;
  std::ifstream file(filePath);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  } else {
    while (!file.eof()) {
      std::getline(file, month, ' ');
      std::getline(file, day, ' ');
      std::getline(file, hours, ':');
      std::getline(file, minutes, ':');
      std::getline(file, seconds, ' ');
      std::getline(file, ipAdd, ':');
      std::getline(file, port, ' ');
      std::getline(file, error);
      numRecords++;
      // Crear un objeto de la clase Registro
      int dia = std::stoi(day);
      int puerto = std::stoi(port);
      Registro tmpRec(month, day, hours, minutes, seconds, ipAdd, port, error);
      listaRegistros.push_back(tmpRec);
      std::cout << month << " " << day << " " << ipAdd << " ";
      std::cout << dia << " " << puerto << std::endl;
    }
    file.close();
  }
}

void Bitacora::leerArchivoTest(std::string filePath) {
}

int Bitacora::particionar(int low, int high) {
  Registro pivot = listaRegistros[high];
  int i = (low - 1); // Índice del elemento más pequeño

  for (int j = low; j <= high - 1; j++) {
    numComparisons++;
    if (listaRegistros[j].getFechaHora() <= pivot.getFechaHora()) {
      i++;
      // Intercambiar los elementos
      Registro temp = listaRegistros[i];
      listaRegistros[i] = listaRegistros[j];
      listaRegistros[j] = temp;
      numSwaps++;
    }
  }
  // Intercambiar los elementos
  Registro temp = listaRegistros[i + 1];
  listaRegistros[i + 1] = listaRegistros[high];
  listaRegistros[high] = temp;

  numSwaps++;
  return (i + 1);
}

void Bitacora::quickSort(int low, int high) {
  if (low < high) {
    int pi = particionar(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

void Bitacora::bubbleSort() {
  int i, j;
  bool swapped;
  int numSwaps = 0, numComparisons = 0;

  for (i = 0; i < listaRegistros.size(); i++) {
    swapped = false;
    for (j = 0; j < listaRegistros.size() - i - 1; j++) {
      numComparisons++;
      if (listaRegistros[j].getFechaHora() > listaRegistros[j + 1].getFechaHora()) {
        // Intercambiar los elementos
        Registro temp = listaRegistros[j];
        listaRegistros[j] = listaRegistros[j + 1];
        listaRegistros[j + 1] = temp;
        swapped = true;
        numSwaps++;
      }
    }

    // Si no se intercambiaron dos elementos
    // en la iteración más interna, entonces termina
    if (swapped == false)
      break;
  }
  std::cout << "BubbleSort: " << numComparisons << " comparaciones, " << numSwaps << " swaps." << std::endl;
}

void Bitacora::ordenarRegistros() {
  numComparisons = 0; // Resetear contadores para QuickSort
  numSwaps = 0;
  
  auto start = std::chrono::high_resolution_clock::now();
  bubbleSort();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "BubbleSort tomó " << duration.count() << " microsegundos." << std::endl;

  numComparisons = 0; // Resetear contadores para QuickSort
  numSwaps = 0;
  start = std::chrono::high_resolution_clock::now();
  quickSort(0, listaRegistros.size() - 1);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "QuickSort: " << numComparisons << " comparaciones, " << numSwaps << " swaps." << std::endl;
  std::cout << "QuickSort tomó " << duration.count() << " microsegundos." << std::endl;
}

int Bitacora::busquedaBinaria(time_t fecha) {
  int inicio = 0, fin = listaRegistros.size() - 1;
  while (inicio <= fin) {
    int medio = inicio + (fin - inicio) / 2;
    if (listaRegistros[medio].getFechaHora() == fecha)
      return medio;
    if (listaRegistros[medio].getFechaHora() < fecha)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  return -1; // si la fecha no se encuentra en los registros
}

void Bitacora::imprimirRango(time_t fechaInicio, time_t fechaFin) {
  int inicio = busquedaBinaria(fechaInicio);
  int fin = busquedaBinaria(fechaFin);
  if (inicio != -1 && fin != -1) {
    for (int i = inicio; i <= fin; i++) {
      std::cout << listaRegistros[i].getAll() << std::endl;
    }
  } else {
    std::cout << "Las fechas proporcionadas no se encuentran en los registros" << std::endl;
  }
}

void Bitacora::escribirArchivo(std::string filePath) {
  std::ofstream file(filePath);
  if (file.is_open()) {
    for (Registro& registro : listaRegistros) {
      file << registro.getAll() << std::endl;
    }
    file.close();
  } else {
    std::cout << "No se pudo abrir el archivo" << std::endl;
  }
}

void Bitacora::agregarRegistro(Registro registro) {
  listaRegistros.push_back(registro);
}


