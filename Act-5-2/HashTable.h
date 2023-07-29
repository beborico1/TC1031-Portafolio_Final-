#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "IPInfo.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class HashTable {
public:
  HashTable(size_t size)
      : size(size), count(0), collisions(0), table(size) {
  }

  void insert(std::string key, IPInfo value) {
    size_t index = hash(key) % size;

    // Incrementa el contador de colisiones si ya hay elementos en esta posición de la tabla hash
    if (!table[index].empty()) {
      ++collisions;
    }

    // Encuentra si la clave ya está en la lista en el índice
    for(auto& pair : table[index]) {
      if(pair.first == key) {
        throw std::runtime_error("Clave duplicada");
      }
    }

    // Inserta el par clave-valor en la lista
    table[index].push_back(std::make_pair(key, value));
    ++count;
  }

  IPInfo *find(std::string key) {
    size_t index = hash(key) % size;

    // Busca la clave en la lista en el índice
    for(auto& pair : table[index]) {
      if(pair.first == key) {
        return &(pair.second);
      }
    }

    return nullptr;  // Si la clave no se encuentra
  }

  size_t getCollisionCount() const { return collisions; }

  void getIPSummary(HashTable &hashTable, const std::string &ip) {
    // Busca la IP en la tabla hash
    IPInfo *info = hashTable.find(ip);
    if (info == nullptr) {
      std::cout << "No se encontró la IP " << ip << "\n";
      return;
    }

    // Imprime la información de la IP
    std::cout << "IP: " << info->getIP() << "\n";
    std::cout << "Total de direcciones accesadas desde la IP: "
              << info->getOutboundCount() << "\n";
    std::cout << "Total de intentos de acceso a la IP: "
              << info->getInboundCount() << "\n";

    // Obtiene las direcciones IP a las que se accedió y las ordena en orden
    // descendente
    std::vector<std::string> accessedIPs = info->getAccessedIPs();
    std::sort(accessedIPs.begin(), accessedIPs.end(),
              std::greater<std::string>());

    // Imprime las direcciones IP a las que se accedió
    std::cout << "Direcciones IP accesadas:\n";
    for (const auto &accessedIP : accessedIPs) {
      std::cout << accessedIP << "\n";
    }
  }

private:
  size_t hash(std::string key) {
    std::stringstream ss(key);
    int a, b, c, d; // los cuatro octetos de la IP
    char ch;        // para el '.'
    ss >> a >> ch >> b >> ch >> c >> ch >> d;
    return ((a << 24) | (b << 16) | (c << 8) | d) % size;
  }

  size_t size;
  size_t count;
  size_t collisions;
  std::vector<std::list<std::pair<std::string, IPInfo>>> table;
};

#endif // HASHTABLE_H
