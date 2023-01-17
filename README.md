TCP Client Server Echo Program
=========================================================================================================================
A socket is a communication mechanism and is identified by an integer that is called the socket descriptor. A socket includes a data structure consisting of the following five data items: 

* Protocol ID
* Destination Host Address
* Destination Port Number
* Local Host Address
* Local Port Number

TCP Echo Client Implementation
-------------------------------------------------------------------------------------------------------------------------
* Create a socket and bind it to a port number
* After binding, accept connection from client
* Receive data from client using recv() function

TCP Echo Server Implementation
-------------------------------------------------------------------------------------------------------------------------
* Create Socket
* Specify client address, port number, message from command line
* Use send() and recv() functions

Project Requirements
-------------------------------------------------------------------------------------------------------------------------
1. Server
  
      A. Add code to listen for connections

      B. Add code to accept connections from client

      C. Add code to receive data from a client connection

      D. Add code to echo data received by the server back to client
  
2. Client 

      A. Add code to send data to the server

      B. Add ccode to receive data from the server

      C. Print the data received from the server
  
Compile and Run
-------------------------------------------------------------------------------------------------------------------------
1. Compile and Run Server
2. Compile and Run Client 
  - Use command line arguements 127.0.0.1 8899 message
