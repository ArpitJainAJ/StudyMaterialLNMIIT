//Include standard libraries
#include<stdio.h>
#include<stdlib.h>
//include socket function libraries
#include<sys/types.h>
#include<sys/socket.h>	//for socket APIs
#include<netinet/in.h>	//structure for storing address information

int main()
{
	// create the client socket
	int client_sockD; 			//to hold socket descripter
	client_sockD = socket(AF_INET,SOCK_STREAM,0);

	// declaring the structure for the address before connecting
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;		//IPv4 address

	// we can pass port number as a integer but structure variable accepts in network byte only, hence cnversion function htons is used
	servAddr.sin_port = htons(9001);	//use some unused port

	// specifying local(0.0.0.0)(INADDR_ANY) or actual address
	servAddr.sin_addr.s_addr = INADDR_ANY;

	// attempt a connection
	if(connect(client_sockD,(struct sockaddr *) &servAddr,sizeof(servAddr))==-1)
		printf("Connection is unsuccessful\nSome error handling needs to be done\n");
	else
	{
		//printf("Connection successful");
		// receive data from user in a string
		char strData[256];
		recv(client_sockD, strData, sizeof(strData), 0);
		printf("%s",strData);
	}
	//closing the socket
	close(client_sockD);

	return 0;
}

