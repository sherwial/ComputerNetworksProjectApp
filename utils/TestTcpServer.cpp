#include "TcpServer.hpp"

#include <iostream>

int main(int argc, char ** argv)
{
	int bufferlength = 1024;
	int port = 19011;
	int maxConnections = 3;
	std::string addressStr = "128.153.180.189";
	
	TcpServer server;
	server.Bind(addressStr.c_str(), port);
	server.Listen(maxConnections);

	char buffer[bufferlength];
	while(1)
	{
		int newSocket;
		server.Accept(newSocket);
		server.Read(newSocket, buffer, bufferlength);
		std::cout << buffer << std::endl;
	}
} // main