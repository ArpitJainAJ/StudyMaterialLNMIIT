//Include standard libraries
#include<stdio.h>
#include<stdlib.h>
//include socket function libraries
#include<sys/types.h>
#include<sys/socket.h>	//for socket APIs
#include<netinet/in.h>	//structure for storing address information

int main()
{
	// data to be send to client
	char serverData[256] = "Hello Client, This message is from Server...\n";

	// create the server socket
	int server_sockD; 			//to hold socket descripter
	server_sockD = socket(AF_INET,SOCK_STREAM,0);

	// declaring the structure for the address before connecting
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;		//IPv4 address

	// we can pass port number as a integer but structure variable accepts in network byte only, hence cnversion function htons is used
	servAddr.sin_port = htons(9001);	//use some unused port

	// specifying local(0.0.0.0)(INADDR_ANY) or actual address
	servAddr.sin_addr.s_addr = INADDR_ANY;

	// binding server to the specified IP and port
	bind(server_sockD, (struct sockaddr*) &servAddr, sizeof(servAddr));

	// listen for connections one at a time
	listen(server_sockD,1);

	// int to hold client socket
	int client_socket;
	client_socket = accept(server_sockD, NULL, NULL);

	// send message to client socket
	send(client_socket, serverData, sizeof(serverData), 0);

	// close the server scoket
	close(server_sockD);

	return 0;
}

