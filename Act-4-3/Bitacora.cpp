#include "Bitacora.h"

Bitacora::Bitacora() { // Complejidad computacional: O(1)
  listaRegistros.clear();
}

Bitacora::~Bitacora() { // Complejidad computacional: O(1)
  listaRegistros.clear();
}
      
// Ref: https://www.cplusplus.com/doc/tutorial/files/
void Bitacora::leerArchivo(const std::string& filename, std::map<std::string, std::vector<Registro>>& adjList) { // Complejidad computacional: O(n)
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    int numIPs, numIncidencias;
    file >> numIPs >> numIncidencias;

    std::string ip;
    std::vector<std::string> ips;
    for (int i = 0; i < numIPs; ++i) {
        file >> ip;
        ips.push_back(ip);
    }

    std::string line;
    std::getline(file, line); // Consume the new line character after numIncidencias

    for (int i = 0; i < numIncidencias; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);

        Registro inc;
        std::string mes, dia, hora, ipOrigen, ipDestino, razon;
        double peso;

        ss >> mes >> dia >> hora >> ipOrigen >> ipDestino >> peso;
        std::getline(ss, razon);

        inc.setMes(mes);
        inc.setDia(std::stoi(dia));
        inc.setHora(hora);
        inc.setIpOrigen(ipOrigen.substr(0, ipOrigen.find_first_of(':'))); // Add this
        inc.setIpDestino(ipDestino.substr(0, ipDestino.find_first_of(':'))); // Add this
        inc.setPeso(peso);
        inc.setRazon(razon);
        inc.setRazon(inc.getRazon().substr(1)); // skip leading space

        adjList[inc.getIpOrigen()].push_back(inc);
    }
}

// Ref: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
void Bitacora::gradoSalida(std::map<std::string, std::vector<Registro>>& adjList) { // Complejidad computacional: O(n)
    std::ofstream file("grados_ips.txt");
    if (!file) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    // Crear un 'priority_queue' donde cada elemento es un par (grado de salida, IP)
    std::priority_queue<std::pair<int, std::string>> pq;

    // Iterar sobre la lista de adyacencia
    for (const auto& pair : adjList) {
        // Escribir en el archivo el grado de salida para la IP actual
        file << pair.first << " tiene un grado de salida de " << pair.second.size() << '\n';

        // Agregar el par (grado de salida, IP) a la cola de prioridad
        pq.push(std::make_pair(pair.second.size(), pair.first));
    }

    // Aquí, guardar el valor del bootMaster
    if (!pq.empty()) {
        std::pair<int, std::string> p = pq.top();
        bootMaster = p.second;

        // Imprimir cuántas conexiones salientes tiene el bootmaster
        std::cout << "El bootmaster es: " << bootMaster << " con " << p.first << " conexiones salientes." << std::endl;
    }

    file.close();
}

void Bitacora::mayorGradoSalida() { // Complejidad computacional: O(1)
    std::ofstream file("mayores_grados_ips.txt");
    if (!file) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    // Extraer los 5 nodos con los grados de salida más altos
    for (int i = 0; i < 5; ++i) {
        if (pq.empty()) break;

        std::pair<int, std::string> top = pq.top();
        pq.pop();

        file << top.second << " tiene un grado de salida de " << top.first << '\n';
    }

    file.close();
}

std::string Bitacora::obtenerBootMaster() { // Complejidad computacional: O(1)
    return bootMaster;
}

// algoritmo de Dijkstra
// Ref: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
std::map<std::string, int> Bitacora::dijkstra(const std::map<std::string, std::vector<Registro>>& adjList, const std::string& src) { // Complejidad computacional: O(n^2)
    // Inicialización de distancias a infinito
    std::map<std::string, int> dist;
    for (const auto& pair : adjList) {
        dist[pair.first] = std::numeric_limits<int>::max();
    }
    dist[src] = 0;

    // Comparador para el heap
    auto comp = [&](const std::string& a, const std::string& b) {
        return dist[a] > dist[b];
    };
    std::priority_queue<std::string, std::vector<std::string>, decltype(comp)> pq(comp);

    pq.push(src);

    while (!pq.empty()) {
        std::string u = pq.top();
        pq.pop();

        for (const Registro& reg : adjList.at(u)) {
            std::string v = reg.getIpDestino();
            int weight = reg.getPeso();  // En este caso, asumo que el peso se define en la clase Registro
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(v);
            }
        }
    }

    return dist;
}

// Ref: https://en.cppreference.com/w/cpp/types/numeric_limits
void Bitacora::guardarDistanciasYObtenerIPMasLejana(const std::map<std::string, int>& distancias) { // Complejidad computacional: O(n)
    std::ofstream file("distancia_bootmaster.txt");
    if (!file) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    int maxDist = -1;
    std::string ipMasLejana;

    for (const auto& pair : distancias) {
        file << pair.first << " " << pair.second << '\n';
        
        if (pair.second > maxDist) {
            maxDist = pair.second;
            ipMasLejana = pair.first;
        }
    }

    std::cout << "La IP que requiere más esfuerzo para atacar (más lejana) es: " << ipMasLejana << " con distancia: " << maxDist << '\n';
    file << "La IP que requiere más esfuerzo para atacar (más lejana) es: " << ipMasLejana << " con distancia: " << maxDist << '\n';
}
