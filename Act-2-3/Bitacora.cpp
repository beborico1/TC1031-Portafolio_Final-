/* 
    Autores: 
        A01252831 - Luis Carlos Rico Almada
        A01709011 - Ayetza Yunnuen Infante García
    Fecha: 
        10/07/2023
    Bitacora.cpp:
        Implementación de la clase Bitacora
*/

#include "Bitacora.h"
#include "Fecha.h"
#include <chrono>
#include <fstream>
#include <sstream> 
#include <iterator>

Bitacora::Bitacora() : numComparisons(0), numSwaps(0) { // Complejidad computacional: O(1)
  // Constructor: Aquí puedes inicializar las variables miembro si es necesario.
  //std::cout << "Constructor de Bitacora" << std::endl;
}

Bitacora::~Bitacora() { // Complejidad computacional: O(1)
  // Destructor: Aquí puedes liberar los recursos si es necesario.
  //std::cout << "Destructor de Bitacora" << std::endl;
}

void Bitacora::escribirArchivo(std::string filePath) {
    std::cout << "Escribiendo registros en el archivo " << filePath << "..." << std::endl;
    std::ofstream file(filePath);

    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
    }

    for (const Registro& registro : listaRegistros) {
    registro.writeAll(file);
    file << '\n';  // Añadir un salto de línea al final de cada registro
  }

  file.close();
  std::cout << "Se escribieron " << listaRegistros.size() << " registros en el archivo " << filePath << std::endl;

    //std::cout << "Escribiendo registros..." << std::endl;

    //try {
        //size_t chunk_size = 1000; // Define tu propio tamaño de chunk
        //for (size_t i = 0; i < listaRegistros.size(); i += chunk_size) {
            //for (size_t j = i; j < i + chunk_size && j < listaRegistros.size(); ++j) {
                //std::cout << "Me gustaria escribir en el archivo el registro: " << listaRegistros[j].getAll() << std::endl;
                //file << listaRegistros[j].getAll() << std::endl;
            //}
            //file.flush(); // Limpia el búfer de escritura después de cada chunk
        //}
        //std::cout << "Se escribieron " << listaRegistros.size() << " registros en el archivo " << filePath << std::endl;
    //} catch (const std::exception& e) {
        //std::cout << "Error al escribir en el archivo." << std::endl;
        //file.close();
        //throw;
    //}

    //std::cout << "Cerrando el archivo..." << std::endl;
    //file.close();
    //std::cout << "Archivo cerrado." << std::endl;
}

void Bitacora::leerArchivo(std::string filePath) { 
  listaRegistros = DoublyLinkedList<Registro>();
  // Complejidad computacional: O(n)
  std::ifstream file(filePath);
  
  if (!file.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
  }

  try {
    std::string line;
    while (std::getline(file, line)) {
      std::istringstream lineStream(line);
      std::string month, day, time, ipAdd, port, error;
      lineStream >> month >> day >> time >> ipAdd >> port >> error;

      // Validar que se hayan leído todos los campos correctamente
      if (lineStream.fail()) {
        std::cout << "Error al leer los campos del registro: " << line << std::endl;
        continue; // Omitir este registro e ir al siguiente
      }

      // Crear un objeto de la clase Fecha
      std::string fechaStr = month + " " + day + " " + time; // combina la fecha y la hora en un solo string
      Fecha fecha(fechaStr); // ahora puedes usar el constructor de Fecha que has proporcionado

      // Crear un objeto de la clase Registro
      Registro tmpRec(fecha, ipAdd, port, error); // Suponiendo que el constructor de Registro tome un objeto Fecha en lugar de una serie de strings
      listaRegistros.push_back(tmpRec);
    }
    std::cout << "Se leyeron " << listaRegistros.size() << " registros del archivo " << filePath << std::endl;
  } catch (const std::exception& e) {
    file.close();
    throw;
  }
  // imprimir primer timestamp de la lista
  //std::cout << "Primer timestamp de la lista: " << listaRegistros[0].getFechaHora() << std::endl;
  // imprimir último timestamp de la lista
  //std::cout << "Último timestamp de la lista: " << listaRegistros[listaRegistros.size() - 1].getFechaHora() << std::endl;
  
  file.close();
  //listaRegistros.display();
}

int Bitacora::particionar(int low, int high) { // Complejidad computacional: O(n)
  Registro pivot = listaRegistros[high];
  int i = (low - 1); // Índice del elemento más pequeño

  for (int j = low; j <= high - 1; j++) {
    numComparisons++;
    if (listaRegistros[j] <= pivot) {
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

void Bitacora::quickSort(int low, int high) { // Complejidad computacional: O(n log n)
  if (low < high) {
    int pi = particionar(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

void Bitacora::bubbleSort() { // Complejidad computacional: O(n^2)
  //std::cout << "Ordenando registros con BubbleSort..." << std::endl;
  size_t i, j;
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

void Bitacora::ordenarRegistros() { // Complejidad computacional: O(n^2)
  numComparisons = 0; // Resetear contadores para QuickSort
  numSwaps = 0;

  // Crea una copia del la lista doblemente ligada original
  DoublyLinkedList<Registro> copiaListaRegistros = listaRegistros;

  auto start = std::chrono::high_resolution_clock::now();
  bubbleSort();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "BubbleSort tomó " << duration.count() << " microsegundos." << std::endl;

  //std::cout << "Imprimiendo los primeros 10 registros..." << std::endl;
  for (int i = 0; i < 10; i++) {
    //std::cout << "Registro " << i << ": " << listaRegistros[i].getAll() << std::endl;
  }

  // Restaura el vector original antes de QuickSort.
  listaRegistros = copiaListaRegistros;

  //std::cout << "Ordenando registros con QuickSort..." << std::endl;

  numComparisons = 0; // Resetear contadores para QuickSort
  numSwaps = 0;
  start = std::chrono::high_resolution_clock::now();
  quickSort(0, listaRegistros.size() - 1);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "QuickSort: " << numComparisons << " comparaciones, " << numSwaps << " swaps." << std::endl;
  std::cout << "QuickSort tomó " << duration.count() << " microsegundos." << std::endl;

  //std::cout << "Imprimiendo los primeros 10 registros..." << std::endl;
  for (int i = 0; i < 10; i++) {
    //std::cout << "Registro " << i << ": " << listaRegistros[i].getAll() << std::endl;
  }

  // Restaura el vector original antes de QuickSort.
  listaRegistros = copiaListaRegistros;

  //std::cout << "Ordenando registros con Merge Sort..." << std::endl;
  start = std::chrono::high_resolution_clock::now();
  listaRegistros.sort();
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "MergeSort tomó " << duration.count() << " microsegundos." << std::endl;

  //std::cout << "Imprimiendo los primeros 10 registros..." << std::endl;
  for (int i = 0; i < 10; i++) {
    //std::cout << "Registro " << i << ": " << listaRegistros[i].getAll() << std::endl;
  }

  escribirArchivo("bitacora_ordenada.txt");
}

int Bitacora::busquedaBinaria(time_t fecha) {
  std::cout << "Buscando la fecha " << fecha << " en la bitácora..." << std::endl;

  // Verificar si la lista está ordenada
  if (!isListaOrdenada()) {
    std::cout << "La lista no está ordenada. Ordena la lista antes de realizar la búsqueda binaria." << std::endl;
    return -1;
  }

  auto inicio = listaRegistros.begin();
  auto fin = listaRegistros.end();
  --fin; // Movemos el fin al último elemento válido
  size_t size = std::distance(inicio, fin) + 1;
  std::cout << "Tamaño de la lista: " << size << std::endl;

  //std::cout << "Incio menor o igual a fin? " << (std::distance(inicio, fin) >= 0) << std::endl;

  while (std::distance(inicio, fin) >= 0) {
    auto distancia = std::distance(inicio, fin);
    auto medio = inicio;
    std::advance(medio, distancia / 2);

    //std::cout << "Medio: " << (*medio).getAll() << std::endl;

    time_t fechaMedio = (*medio).getFechaHora();
    //std::cout << "Fecha medio: " << fechaMedio << std::endl;

    if (std::abs(fechaMedio - fecha) <= 1) {
      // Las fechas son consideradas iguales dentro de una tolerancia de 1 segundo
      std::cout << "Se encontró la fecha " << fecha << " en la bitácora." << std::endl;
      size_t distancia = std::distance(listaRegistros.begin(), medio);
      //std::cout << "Distancia: " << distancia << std::endl;
      return distancia;
    }

    if (fechaMedio < fecha) {
      //std::cout << "Fecha medio es menor que fecha" << std::endl;
      inicio = medio;
      ++inicio; // Incrementamos inicio un paso después de medio
      //std::cout << "Inicio: " << (*inicio).getAll() << std::endl;
    } else {
      //std::cout << "Fecha medio es mayor que fecha" << std::endl;
      fin = medio;
      if (inicio != fin) {
        --fin; // Decrementamos fin un paso antes de medio
      }
      std::cout << "Fin: " << (*fin).getAll() << std::endl;
    }
  }

  //std::cout << "No se encontró la fecha " << fecha << " en la bitácora." << std::endl;
  return -1;
}

bool Bitacora::isListaOrdenada() const {
    // imprimir toda la lista para verificar que esté ordenada
  //std::cout << "Imprimiendo la lista..." << std::endl;
    //std::cout << "Imprimiendo los timestamps de cada registro..." << std::endl;
  for (auto it = listaRegistros.begin(); it != listaRegistros.end(); ++it) {
    //std::cout << (*it).getAll() << std::endl;
  }
  // imprimir los timestamps de cada registro para verificar que esté ordenada
  //std::cout << "Imprimiendo los timestamps de cada registro..." << std::endl;
  for (auto it = listaRegistros.begin(); it != listaRegistros.end(); ++it) {
    //std::cout << (*it).getFechaHora() << std::endl;
  }
  
  auto it = listaRegistros.begin();
  //std::cout << "Primer registro: " << (*it).getFechaHora() << std::endl;
  auto prevIt = it;
  ++it;
  //std::cout << "Segundo registro: " << (*it).getFechaHora() << std::endl;

  while (it != listaRegistros.end()) {
    //std::cout << "Comparando " << (*prevIt).getFechaHora() << " con " << (*it).getFechaHora() << std::endl;
    if ((*prevIt).getFechaHora() > (*it).getFechaHora()) {
      //std::cout << "El registro " << (*prevIt).getFechaHora() << " es mayor que " << (*it).getFechaHora() << std::endl;
      return false;
    }
    ++prevIt;
    ++it;
  }
  std::cout << "La lista si esta ordenada " << std::endl;
  return true;
}

void Bitacora::imprimirRango(time_t fechaInicio, time_t fechaFin) { // Complejidad computacional: O(n)
  //std::cout << "Imprimiendo registros entre " << fechaInicio << " y " << fechaFin << std::endl;
  int inicio = busquedaBinaria(fechaInicio);
  int fin = busquedaBinaria(fechaFin);

  // std::cout << "Inicio: " << inicio << std::endl;
  // std::cout << "Fin: " << fin << std::endl;

  std::ofstream myfile ("resultado_busqueda.txt"); // crear un objeto de tipo ofstream

  std::cout << "Escribiendo resultados en el archivo resultado_busqueda.txt..." << std::endl;
  
  if (inicio == -1 || fin == -1) {
    std::cout << "Uno o ambos rangos de fecha no se encontraron en la bitácora." << std::endl;
    myfile << "Uno o ambos rangos de fecha no se encontraron en la bitácora." << std::endl;
  } else {
    std::cout << "Se encontraron " << fin - inicio + 1 << " registros." << std::endl;
    for (int i = inicio; i <= fin; i++) {
      //std::cout << "Registro " << i << std::endl;
      
      //std::cout << "Registro " << i << ": " << listaRegistros[i].getAll() << std::endl;
      // std::cout << listaRegistros[i].getAll() << std::endl;
      //std::cout << "Escribiendo en el archivo..." << std::endl;
      //myfile << listaRegistros[i].getAll() << std::endl; // escribir en el archivo
      //std::cout << "Escrito." << std::endl;
      listaRegistros[i].writeAll(myfile);
      myfile << '\n';
    }
  }
  std::cout << "Cerrando el archivo..." << std::endl;
  myfile.close(); // cerrar el archivo
  std::cout << "Archivo cerrado." << std::endl;
}


void Bitacora::agregarRegistro(Registro registro) { // Complejidad computacional: O(1)
  listaRegistros.push_back(registro);
}


