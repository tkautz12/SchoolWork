#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <signal.h>

int main()
{
	struct sockaddr_in socketAddress;
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    //socketAddress.sin_port = htons(my_atoi(8080));
    socketAddress.sin_addr.s_addr =inet_addr("123.12.12.0");
	int x=INADDR_ANY;
	printf("%i\n", socketAddress.sin_addr.s_addr);
	return 0;
}