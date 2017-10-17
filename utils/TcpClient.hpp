#ifndef _TCP_CLIENT
#define _TCP_CLIENT

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include "unistd.h"
#include <arpa/inet.h>

class TcpClient
{
public:
	TcpClient();

	bool Connect(std::string address, int port);

	bool Send(uint8_t * buffer, int bufferlength);

	bool Close();

private:
	struct sockaddr_in this_address;
	struct sockaddr_in server_address;
	int port;
	int sockfd;
	
	// To receive a message confirmed transmission
	static int messageConfirmationLength;
	static char returnMessageBuffer[2];
	int readReturnVal;

}; // TcpClient

#endif /* TCP_CLIENT */
