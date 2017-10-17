#include "Address.hpp"
#include "UdpSocket.hpp"
#include "TcpSocket.hpp"
#include <map>
#include <string>

// Purpose: Serve as API for app
class NetworkCommunicationApp
{
public:
	NetworkCommunicationApp();

	bool tcp_connect(Address in);

	bool send_packet_udp(uint8_t * data, int length);

	bool send_packet_tcp(uint8_t * data, int length);

private:

	// Mapps the ips and ports to the thing
	std::map<std::string, int> mapping;

} // NetworkCommunicationApp