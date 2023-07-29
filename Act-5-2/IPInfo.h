#ifndef IPINFO_H
#define IPINFO_H

#include <string>
#include <vector>

class IPInfo {
public:
    // Constructor
    IPInfo(std::string ip = "", int outboundCount = 0, int inboundCount = 0)
        : ip(ip), outboundCount(outboundCount), inboundCount(inboundCount) {}

    // Métodos para acceder y modificar los datos
    std::string getIP() const { return ip; }
    int getOutboundCount() const { return outboundCount; }
    int getInboundCount() const { return inboundCount; }
    void incrementOutboundCount() { outboundCount++; }
    void incrementInboundCount() { inboundCount++; }

    // Nueva función para agregar una dirección IP a la que se accedió
    void addAccessedIP(std::string accessedIP) { accessedIPs.push_back(accessedIP); }

    // Nueva función para obtener las direcciones IP a las que se accedió
    std::vector<std::string> getAccessedIPs() const { return accessedIPs; }

private:
    std::string ip;
    int outboundCount;
    int inboundCount;
    std::vector<std::string> accessedIPs;  // Almacena las direcciones IP a las que se accedió desde esta IP
};

#endif  // IPINFO_H
