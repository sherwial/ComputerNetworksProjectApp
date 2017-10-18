#include "TcpServer.hpp"
#include <iostream>

int TcpServer::messageConfirmationLength = 2;
char TcpServer::returnMessageBuffer[2] = {'A','B'};

TcpServer::TcpServer()
{
	opt = 1;

	// Create TCP socket file descriptor
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		std::cout << "Socket not created successfully" << std::endl;
	} // if

	// Setting the socket options
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		std::cout << "setsockopt failed" << std::endl;
	} // if

} // TcpServer

bool TcpServer::Bind(std::string host, int port)
{
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( port );
	addr_len = sizeof(address);

	// Forcefully attaching socket to the port 8080
	if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
		return 0; // Bind failed
	} // if
	 
	return 1; // Successful bind
} // bind

bool TcpServer::Listen(int num_connections)
{
	if (listen(socket_fd, num_connections) < 0)
	{
		return 0; // Listen failed
	} // if

	return 1; // Successful listen
} // listen
 
bool TcpServer::Accept(int & new_socket)
{
	if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len))<0)
	{
		return 0;
	} // if

	return 1;
}

bool TcpServer::Read(int accepted_socket, uint8_t * buffer, int buffer_length)
{
	val_from_read = read( accepted_socket, buffer, buffer_length );

	send(accepted_socket , returnMessageBuffer , messageConfirmationLength , 0 );
} // read