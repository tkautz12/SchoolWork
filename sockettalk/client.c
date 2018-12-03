#define _POSIX_SOURCE
#include "my.h"
//#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
//#include <strings.h>
#include <signal.h>
#define h_addr h_addr_list[0]

int main(int argc, char *argv[]){
	if(argc !=3){
    	my_str("Input wrong try again using format: ./client <hostname> <port>\n");
    	exit(0);
    }
    int usernameTest=0;
    char readBuffer[2048];
    char writeBuffer[1024];
    char message[2048];
    int n;
    int k;
    int test;
    char username[1024];
    memset(username,'\0', 1024);
    pid_t pid;
    //creat the sockBOIIIIIIIIIII
    int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    if (sockBOIIIII<0){
    	my_str("Socket Error\n");
    	exit(0);
    }
    my_str("Please enter a username\n");
    while(1){
  	k=read(0, username, 1024);
  	if(k!=0)
  		break;
  	}
 	if(username[k-1]=='\n')
       	username[k-1]='\0';
  	usernameTest++;
  	my_str("Username set to: ");
	my_str(username);
  	my_str(" \n");
    //sockaddr junk
    struct sockaddr_in socketAddress;
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[2]));
    socketAddress.sin_addr.s_addr = inet_addr(argv[1]);
    if(connect(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)))<0){
    	my_str("Connecting error\n");
    	exit(0);
    }
    int testBOI=write(sockBOIIIII,username,my_strlen(username));
    if(testBOI<0){
    	my_str("Write error");
    }
    if((pid = fork())<0){
    	my_str("forking error teehee\n");
    }
    else if (pid==0){
	    while(1){
    		memset(writeBuffer,'\0', 2048);
    		memset(message,'\0', 2048);

  			n = read(0, writeBuffer, 1024);
			if (n<0){
           		my_str("Read error from client\n");
	       	}
        	else{
        		if(my_strncmp(writeBuffer, "/nick", 5)==0){
        			if(writeBuffer[n-1]=='\n')
       					writeBuffer[n-1]='\0';
        		}
       			my_strcpy(message, writeBuffer);
	   			if(my_strncmp(writeBuffer,"/exit",5)==0){
        			my_str("Exitting from server\n");
        			test=write(sockBOIIIII,message,my_strlen(message));
       				if(test<0){
       					my_str("Write error");
    				}
        			kill(0, SIGKILL);
					kill(1, SIGKILL);
       				exit(0);
       			}
       		    else{
       			test=write(sockBOIIIII,message,my_strlen(message));
       			if(test<0){
       				my_str("Write error");
    			}
      			}		
	   		}		
    	}
	}
	else{
		while(1){
			memset(readBuffer,'\0', 2048);
			if(recv(sockBOIIIII, readBuffer, 2048, 0)<0){
    			my_str("Error receiving dataz\n");
    		}
	    	else{
    			my_str(readBuffer);
    		}
		}
	}
    if(close(sockBOIIIII)<0){
  		my_str("Socket closing error\n");
  		exit(0);
  	}

  	return 0;
}
//okay we're hot on the trail lets fucking send it boiiiisss
/*
int main(int argc, char *argv[]){
	if(argc !=3){
    	my_str("Input wrong try again using format: ./client <hostname> <port>\n");
    	exit(0);
    }
    int usernameTest=0;
    char buffer1[2048];
    char message[2048];
    int n;
    int k;
    int test;
    char username[1024];
    //creat the sockBOIIIIIIIIIII
    int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    if (sockBOIIIII<0){
    	my_str("Socket Error\n");
    	exit(0);
    }
    my_str("Please enter a username\n");
    //sockaddr junk
    struct sockaddr_in socketAddress;
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[2]));
    socketAddress.sin_addr.s_addr = inet_addr(argv[1]);
    if(connect(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)))<0){
    	my_str("Connecting error\n");
    	exit(0);
    }
    memset(username,'\0', 1024);
    while(1){
    	memset(buffer1,'\0', 2048);
    	memset(message,'\0', 2048);
  		
  		if(usernameTest==0){
  			while(1){
  			 k=read(0, username, 1024);
  			 if(k!=0)
  			 	break;
  			}
  			if(username[k-1]=='\n')
            	username[k-1]='\0';
  			usernameTest++;
  			my_str("Username set to: ");
  			my_str(username);
  			my_str(" \n");

  		} 
  		else{
  		n = read(0, buffer1, 1024);
  		if (n<0){
           	my_str("Read error from client\n");
        }
        else{
        	my_strcpy(message, username);
            my_strcat(message, ": ");
            my_strcat(message, buffer1);
    		if(my_strncmp(buffer1,"/exit",5)==0){
        		my_str("Exitting from server\n");
        		exit(0);
        	}
        	
         //    if(my_strncmp(buffer1,"/nick",5)==0){
         //    	memset(username,'\0', 2048);
         //        //username = my_strdup(&buffer1[5]);
	      		// strncpy(username, &(buffer1[6]), 1024);
	      		// strcat(unarray[xx], "\0");
         //        my_str("Username changed to ");
         //        my_str(username);
         //        my_str("\n");
         //    }
            
            else{
           	//my_str("message is ");
            //my_str(message);
            //my_strcat(message, buffer1);
            //my_str("message is ");
            //my_str(message);
        	test=write(sockBOIIIII,message,my_strlen(message));
        	if(test<0){
        		my_str("Write error");
       		}
       	}
       		
    	}
    	if(recv(sockBOIIIII, buffer1, 1024, 0)<0){
    		my_str("Error receiving dataz\n");
    	}
    	else{
    		my_str(buffer1);
    	}
    }
    }
    if(close(sockBOIIIII)<0){
  		my_str("Socket closing error\n");
  		exit(0);
  	}

  	return 0;
}
*/
// CODE NOT WORKING LETS TRY THIS AGAIN BOIIIISSSS
/*
int main(int argc, char *argv[]){
	if(argc !=3){
    	my_str("Input wrong try again using format: ./client <hostname> <port>\n");
    	exit(0);
    }
	int sockBOIIIII;
	int n;
	int test;
	int fd[2];
	pipe(fd);
    struct sockaddr_in socketAddress;
    struct hostent *host;
    char  nick[1024];
    bzero(nick, 1024);
    char buffer1[1024];
    char buffer2[1024];
  	host = gethostbyname(argv[1]);
  	if(host==0){
  		my_str("Host error\n");
  		exit(0);
  	}
   	my_str("Please enter a nickname: \n");
   	if(read(0,nick,1024)<0){
   		my_str("Nickname error\n");
   		exit(0);
   	}
   	my_str("\n");
   	bzero((char *) &socketAddress, sizeof(socketAddress));
  	sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
  	if(sockBOIIIII<0){
  		my_str("Socket error\n");
  		exit(0);
  	}
    socketAddress.sin_port = htons(my_atoi(argv[2]));
    socketAddress.sin_family = AF_INET;
    my_strncpy((char *)host->h_addr, (char *)&socketAddress.sin_addr, host->h_length);
    if(connect(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)))<0){
    	my_str("Connecting error\n");
    	exit(0);
    }
  	n=write(sockBOIIIII, nick, my_strlen(nick));
  	if(n<0){
  		my_str("Nickname write error\n");
  		exit(0);
  	}
  	pid_t pid=fork();
  	if(pid<0){
  		my_str("Forking error\n");
  		exit(0);
  	}
  	else if(pid==0){
  		while(1){
  			bzero(buffer1, 1024);
  			n = read(0, buffer1, 1024); 
  			if (n<0){
            	my_str("Read error from client\n");
        	}
        	else if(n==0){
        		continue;
        	}
        	else{
        		if(my_strncmp(buffer1,"/exit",5)==0){
        			my_str("Exitting from server\n");
        			kill(0,SIGKILL);
        			kill(1,SIGKILL);
        			break;
        		}
        		else{
        			test=write(sockBOIIIII,buffer1,n);
        			if(test<0){
        				my_str("Write error");
        			}
        		}   
     		}
     	}
 	}
 	else{
 		while(1){
 			bzero(buffer2,1024);
    	 	n=read(sockBOIIIII, buffer2, 1024);
     		if(n<0){
     			my_str("Read error from server\n");
     		}
     		else if(n==0){
     			continue;
     		}
     		else{
     			write(1,buffer2,n);
     		}
  		}
  	}	
  	if(close(sockBOIIIII)<0){
  		my_str("Socket closing error\n");
  		exit(0);
  	}

  	return 0;
}
*/