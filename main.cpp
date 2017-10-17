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

		if ( argv[1] == "--transmit" )
		{

		} // if
		
	} // else

} // main

void printHelpMenu()
{
	std::cout << "Argument List:" << std::endl << std::endl;
	std::cout << "\t--receive [IP]" << std::endl;
	std::cout << "\t--relay-list [IP List text file]" << std::endl;
	std::cout << "\t--transmit [text-file]" << std::endl;
} // printHelpMenu