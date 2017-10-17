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
			int port; // Port for transmit

			in.open(argv[2]); // Open file stream

			getline(in, nextLine);
			port = atoi(nextLine.c_str());
			std::cout << port << std::endl;

			while ( getline(in, nextLine) )
			{
				list.push_back(nextLine);
			} // while

			in.close(); // Close file stream

			bool bound = server.Bind("128.153.180.189",port);

			std::cout << bound << " is bound" << std::endl;
			server.Listen(3);

			int socketnew;
			server.Accept(socketnew);
			
		} // if

		if ( argv1 == "--transmit" )
		{
			std::ifstream in;
			TcpClient client;
			int buffer_length = 1024;
			char * buffer = (char *)malloc(buffer_length);
			std::string filename;

			while (1)
			{
				// Get the filename from the user
				std::cin >> filename;
				// Open the file
				in.open(filename.c_str());

				// Transmit each 1024 group of bytes at a time
				while (in)
				{
					in.read(buffer, 1024);
					client.Send(buffer, 1024);
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