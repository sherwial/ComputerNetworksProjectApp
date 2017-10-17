#include "TcpClient.hpp"
#include <iostream>

int TcpClient::messageConfirmationLength = 2;
char TcpClient::returnMessageBuffer[2] = {'A','B'};

TcpClient::TcpClient()
{
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
    	std::cout << "Socket creation failed" << std::endl;
    } // if

    // Set memory of server address
    memset(&server_address, '0', sizeof(server_address));

} // TcpClient

bool TcpClient::Connect(std::string address, int port)
{
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);

	if (inet_pton(AF_INET, address.c_str(), &server_address.sin_addr) <=0)
	{
		return 0; // Failure to 
	} // if

	if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
	{
		return 0;  // Connection failed
	} // if

	return 1; // Success
} // connect

bool TcpClient::Send(uint8_t * buffer, int bufferlength)
{
	send(sockfd, buffer, bufferlength, 0);
	readReturnVal = read(sockfd, returnMessageBuffer, messageConfirmationLength);
	std::cout << returnMessageBuffer << std::endl;
} // send

bool TcpClient::Close()
{
	close(sockfd);
} // close
