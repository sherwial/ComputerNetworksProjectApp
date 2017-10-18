#ifndef _TCP_SERVER
#define _TCP_SERVER

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include "unistd.h"

class TcpServer
{
public:
	TcpServer();

	bool Bind(std::string host, int port);

	bool Listen(int num_connections);

	bool Accept(int & new_socket);

	bool Read(int accepted_socket, uint8_t * buffer, int buffer_length);

private:

	struct sockaddr_in address; // Address of socket
	int socket_fd;
	int val_from_read;
	int addr_len;
	int opt;

	static int messageConfirmationLength;
	static char returnMessageBuffer[2];

}; // TcpSocket

#endif /* _TCP_SERVER */
