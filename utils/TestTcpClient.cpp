
#include <iostream>
#include "TcpClient.hpp"

int main(int argc, char ** argv)
{
	TcpClient client;
	client.Connect("128.153.180.189", 19011);
	int bufferlength = 10;
	uint8_t buffer[bufferlength] = "1234567890";
	client.Send(buffer, bufferlength);
	client.Close();

} // main
