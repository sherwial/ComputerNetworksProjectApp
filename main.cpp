#include <iostream>
#include <fstream>
#include <vector>
#include "TcpServer.hpp"
#include "TcpClient.hpp"

void printHelpMenu();

int main(int argc, char * argv[])
{
	int argMin = 3;
	if (argc < argMin)
	{
		printHelpMenu();
	} // if
	else
	{
		std::string argv1 = argv[1];
		if ( argv1 == "--receive" )
		{
		} // if

		if ( argv1 == "--relay-list" )
		{
			TcpServer server;
			std::vector<TcpClient> clients;
			std::ifstream in;
			std::string nextLine;
			std::vector<std::string> list;
			std::string address; // Port for transmit
			std::string ip;
			int port;

			in.open(argv[2]); // Open file stream

			getline(in, address);
			int position = address.find(':');
			ip = address.substr(0, position);
			port = atoi((address.substr(position+1, address.length())).c_str());
			std::cout << "(" << ip << "," << port << ")" << std::endl;

			while ( getline(in, nextLine) )
			{
				list.push_back(nextLine);
			} // while

			in.close(); // Close file stream

			bool bound = server.Bind(ip.c_str(),port);

			server.Listen(3);

			int socketnew;
			server.Accept(socketnew);

			uint8_t * buffer = (uint8_t *)malloc(1024);
			server.Read(socketnew, buffer, 1024);
			std::cout << buffer << std::endl;
			
		} // if

		if ( argv1 == "--transmit" )
		{
			std::ifstream in;
			std::string ip;
			int port;
			TcpClient client;
			int buffer_length = 1024;
			unsigned char * buffer = (unsigned char *)malloc(buffer_length);
			std::string filename;

			port = atoi(argv[3]);
			client.Connect(ip, port);

			while (1)
			{
				// Get the filename from the user
				std::cin >> filename;
				// Open the file
				in.open(filename.c_str());

				// Transmit each 1024 group of bytes at a time
				while (in)
				{
					in.read(reinterpret_cast<char *>(buffer), 1024);
					client.Send(reinterpret_cast<uint8_t *>(buffer), 1024);
				} // while

				in.close();
			} // while

			in.open(argv1.c_str());

		} // if
		
	} // else

} // main

void printHelpMenu()
{
	std::cout << "Argument List:" << std::endl << std::endl;
	std::cout << "\t--receive [IP]" << std::endl;
	std::cout << "\t--relay-list [IP List text file]" << std::endl;
	std::cout << "\t--transmit ip port" << std::endl;
} // printHelpMenu