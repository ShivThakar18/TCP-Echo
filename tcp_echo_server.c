/*
 * COMP 3271 - Computer Networks
 * Project Part 1 - UDP Time Server - Server Implementation
 * Name: Shiv Thakar
 */

//TCP Echo server program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define	BUFLEN	512											// Maximum length of buffer
#define PORT	8899										// Fixed server port number

int main (void)
{
	struct sockaddr_in server_address;						// Data structure for server address
	struct sockaddr_in client_address;						// Data structure for client address
	int client_address_len = 0;
		
	
	// Populate socket address for the server
	memset (&server_address, 0, sizeof (server_address));	// Initialize server address data structure
	server_address.sin_family = AF_INET; 					// Populate family field - IPV4 protocol
	server_address.sin_port = PORT;							// Set port number
	server_address.sin_addr.s_addr = INADDR_ANY;			// Set IP address to IPv4 value for loacalhost
	 	
	// Create a TCP socket; returns -1 on failure
	int listen_sock;
	if ((listen_sock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
		printf("Error: Listen socket failed!\n");
		exit (1);
	}
	printf("Socket Creation Successful\n");
	// Bind the socket to the server address; returns -1 on failure
	if ((bind(listen_sock, (struct sockaddr *)&server_address, sizeof (server_address))) == -1) {
		printf("Error: binding failed!\n");
		exit (1);
	}
	printf("Socket Bound to Server Address\n");

	// Students to complete this section
	int waitSize = 16;					// size of waiting client
	char buffer[BUFLEN];				// data buffer for message
	int max = sizeof(buffer);			// maximum size to receive data
	char *p = buffer;					// buffer pointer
	int sock;							// socket descriptor
	int len = 0;						// bytes to send and receive
	int n;								

	// Listen for connections...
	printf("Listening for connections...\n");
	if((listen(listen_sock,waitSize) < 0)){// listening error
		printf("Listening Error\n");
		exit(1);
	}

	printf("Accepting Connection...\n");

	// Accept connections from client...
	client_address_len = sizeof(client_address);
	if((sock = accept(listen_sock,(struct sockaddr *)&client_address,&client_address_len))< 0){ // accepting error
		printf("Error Accepting Connection\n");
		exit(1);
	}

	printf("Connection Successful\n");

	// Receive and format the data...
	printf("Receiving message...\n");
	while((n = recv(sock,p,max,0)) > 0){
		p += n;			// move pointer along the buffer char
		max -= n;		// decrement maximum length
		len += n;		// increment length of message

		printf("Message Received: %s\n",buffer);	// print message from client
	
		// Echo data back to the client...
		printf("Sending message back to client\n");
		send(sock, buffer,len,0);	// send message back to the client
	} 

	close(sock);			// close descriptor
	close(listen_sock);		// Close descriptor referencing server socket
	
} // End main
