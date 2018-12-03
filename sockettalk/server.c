#include "my.h"
//#include "list.h"
//#include <stdlib.h>
//#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <arpa/inet.h>
//#include <strings.h>
#include <string.h>

int main(int argc, char* argv[]){
	//version 3.0 lets get it. it works
	if (argc < 2){
		my_str("Usage error try ./server <port>\n");
		exit(0);
	}
	int currentBOIIIII;
	//int numUsers=0;
	//int userSockBOIIIII;
	char usernames[1024][1024];
	memset(&usernames, '\0', sizeof(usernames));
	int userSock[2048];
	memset(&userSock, 0, sizeof(userSock));
	fd_set readfds;
	int bindVar;
	//int user[1024];
	char buffer[2048];
	char message[2048];
	int user;
	int talkingBOI;
	socklen_t addr_size;
	//int userPos=0;
	//char message[1024]="server has been reached";
	int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketAddress;
   	struct sockaddr_in clientAddress;
    addr_size=sizeof(clientAddress);
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[1]));
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    bindVar=bind(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)));
    if(bindVar<0){
    	my_str("Binding error lol\n");
    	exit(0);
    }
    if(listen(sockBOIIIII, 1024)==0){
    	my_str("Listening boiiii\n");
    }
    else{
    	my_str("Listening error lol");
    }
    	FD_ZERO(&readfds);
    	FD_SET(sockBOIIIII, &readfds);
    	//userSock[numUsers]=sockBOIIIII;

    while(1){
    	//might have problems here double check dumbass
    	FD_ZERO(&readfds);
    	FD_SET(sockBOIIIII, &readfds);
    	for (int i = 0; i < 2048; ++i)
    	{
    		if(userSock[i]!=0)
    			FD_SET(userSock[i], &readfds);
    	}
    	//my_str("its repeating this too\n");
    	//my_int(FD_SETSIZE);
		int selectTest=select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
		if(selectTest<0){
			my_str("Sorry select machine broke\n");
			exit(0);
		}
		//my_str("PASSED SELECT");
		//my_int(FD_SETSIZE);
		//for(int i =0; i<FD_SETSIZE;i++){
			//my_str("HERE");
			//int sock= userSock[i];
		if(FD_ISSET(sockBOIIIII,&readfds)){
				//if(sock==sockBOIIIII){
			user=accept(sockBOIIIII, (struct sockaddr*)&clientAddress, &addr_size);
			if(user<0){
				my_str("accepting error lol\n");
				exit(0);
			}
			memset(buffer, '\0', (sizeof buffer));
			recv(user, buffer,2048,0);
    		for (int i = 0; i < 2048; ++i)
    		{
    			if(userSock[i]==0){
    				userSock[i]=user;
    				my_str(buffer);
    				my_str(" this is the username dumbass\n");
    				my_strcpy(usernames[i],buffer);
    				break;
    			}
    		}
    		my_str("Connection accepted from IP: ");
    		my_str(inet_ntoa(clientAddress.sin_addr));
    		my_str(" port : ");
     		my_int(ntohs(clientAddress.sin_port));
     		my_str("\n");
     		my_str("Username is: ");
     		my_str(buffer);
     		my_str("\n");
		}
		else{
		for (int i = 0; i < 2048; ++i)
		{
			memset(buffer, '\0', (sizeof buffer));
			currentBOIIIII=userSock[i];
			talkingBOI=i;
			if(FD_ISSET(currentBOIIIII, &readfds)){
				int testerooski=recv(currentBOIIIII, buffer,2048,0);
				if(testerooski==0){
					my_str("MOOOOOOOOOOOOOOO\n");
					close(currentBOIIIII);
					FD_CLR(currentBOIIIII, &readfds);
					userSock[i]=0;
					memset(&usernames[i], '\0', sizeof(usernames[i]));
				}
				if(my_strncmp(buffer,"/",1)==0){
					my_str("it gets here boyah\n");
					if(my_strncmp(buffer, "/exit", 5)==0){
						userSock[i]=0;
						close(currentBOIIIII);
						FD_CLR(currentBOIIIII, &readfds);
						my_str(usernames[i]);
						my_str(" used command /exit");
						my_str("\n");
						memset(&usernames[i], '\0', sizeof(usernames[i]));
						//my_str("this should be working but it doesnt\n\n\n");
					}
					//CHECK WHAT HAPPENS WITH NO SPACE EX /MEHELLO VS /ME HELLO
					else if(my_strncmp(buffer, "/me ", 4)==0){
						for (int j = 0; j < 2048; ++j)
						{
							if(userSock[j]!=0){
								memset(message, '\0', (sizeof message));
								my_str("message sent to ");
								my_str(usernames[j]);
								my_str("\n");
								my_strcpy(message, usernames[talkingBOI]);
            					my_strcat(message, " ");
            					my_strcat(message, &(buffer[4]));
								send(userSock[j], message,my_strlen(message),0);
							}
						}
					}
					else if(my_strncmp(buffer, "/nick ", 6)==0){
						//my_str("it gets here dawg\n");
						int length=0;
						for(int j=0;j<my_strlen(&(buffer[6]));j++){
							if(buffer[j+6]!=' ' && buffer[j+6]!='	' && buffer[j+6]!='\n'){
								length++;
								break;
							}
						}
							//keep an eye on this one....
						if(length>0){
							//my_str("it gets in this bad boi\n");
							memset(&usernames[i], '\0', sizeof(usernames[i]));
							my_strcpy(usernames[i],&(buffer[6]));
							my_strcat(usernames[i],'\0');
							//my_int(i);
							send(currentBOIIIII, "Username changed \n",32,0);
						}
						else{
							send(currentBOIIIII, "No username given \n",32,0);
						}
						
					}
					send(currentBOIIIII, "Invalid command dawg\n",32,0);
				}
				else{
					for (int j = 0; j < 2048; ++j)
					{
						if(userSock[j]!=0){
							if(buffer[0]!='\0'){
							memset(message, '\0', (sizeof message));
							my_str("message sent to ");
							my_str(usernames[j]);
							my_str("\n");
							my_strcpy(message, usernames[talkingBOI]);
            				my_strcat(message, ": ");
            				my_strcat(message, buffer);
							send(userSock[j], message,my_strlen(message),0);
						}
						}
					}
					//without the username stuff
					// for (int j = 0; j < 2048; ++j)
					// {
					// 	if(userSock[j]!=0){
					// 		my_str("message sent to ");
					// 		my_str(usernames[j]);
					// 		send(userSock[j], buffer,my_strlen(buffer),0);
					// 	}
					// }
				}
			}
		}
	}
		
    }
    FD_ZERO(&readfds);
    for (int j = 0; j < 2048; ++j)
	{
		if(userSock[j]!=0){
			close(userSock[j]);
		}
	}
	close(sockBOIIIII);

    my_str("it gets here");
	return 0;
}
/*
int main(int argc, char* argv[]){
	//version 2.5 kind of working lets try for gold boys
	if (argc < 2){
		perror("Usage error");
		exit(1);
	}
	int numUsers=0;
	int userSockBOIIIII
	int userSock[2048];
	memset(&userSock, 0, sizeof(userSock));
	fd_set readfds;
	int bindVar;
	//int user[1024];
	char buffer[2048];
	int user;
	socklen_t addr_size;
	//int userPos=0;
	//char message[1024]="server has been reached";
	int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketAddress;
   	struct sockaddr_in clientAddress;
    addr_size=sizeof(clientAddress);
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[1]));
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    bindVar=bind(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)));
    if(bindVar<0){
    	my_str("Binding error lol\n");
    	exit(0);
    }
    if(listen(sockBOIIIII, 1024)==0){
    	my_str("Listening boiiii\n");
    }
    else{
    	my_str("Listening error lol");
    }
    	FD_ZERO(&readfds);
    	FD_SET(sockBOIIIII, &readfds);
    	userSock[numUsers]=sockBOIIIII;

    while(1){
    	//might have problems here double check dumbass
    	FD_ZERO(&readfds);
    	FD_SET(sockBOIIIII, &readfds);
    	my_str("its repeating this too\n");
    	my_int(FD_SETSIZE);
		int selectTest=select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
		if(selectTest<0){
			my_str("Sorry select machine broke\n");
			exit(0);
		}
		//my_str("PASSED SELECT");
		my_int(FD_SETSIZE);
		//for(int i =0; i<FD_SETSIZE;i++){
			//my_str("HERE");
			//int sock= userSock[i];
		if(FD_ISSET(sockBOIIIII,&readfds)){
				//if(sock==sockBOIIIII){
			user=accept(sockBOIIIII, (struct sockaddr*)&clientAddress, &addr_size);
			if(user<0){
				my_str("accepting error lol\n");
				exit(0);
			}
				//}if sock==sockboi
    			FD_SET(user, &readfds);
    			numUsers++;
    			my_str("Connection accepted from IP: ");
    			my_str(inet_ntoa(socketAddress.sin_addr));
    			my_str(" port : ");
     		  	my_int(ntohs(socketAddress.sin_port));
     			my_str("\n");
			}
			//else{
				//my_str("gethereWHY ARE YOU JUST REPEATING THE ELSE???");
				// memset(buffer, '\0', (sizeof buffer));
				// int testerooski=recv(sock, buffer,2048,0);
				// my_str(buffer);	
				// if(testerooski==0){
				// 	my_str("MOOOOOOOOOOOOOOO\n");
				// 	close(sock);
				// 	FD_CLR(sock, &readfds);
				// }
				// else{
				// 	send(userSock[1], buffer,my_strlen(buffer),0);
				// 	for(int i=0;i<numUsers;i++){
				// 		int sockBOYO=userSock[i];
				// 		if (sockBOYO!=sockBOIIIII){
				// 			send(sockBOYO, buffer,my_strlen(buffer),0);
				// 		}
				// 	}
				// }

			//}
		//}forloop
		memset(buffer, '\0', (sizeof buffer));
				int testerooski=recv(user, buffer,2048,0);
				my_str(buffer);	
				my_int(testerooski);
				send(user, buffer,my_strlen(buffer),0);
				if(testerooski==0){
					my_str("MOOOOOOOOOOOOOOO\n");
					close(user);
					FD_CLR(user, &readfds);
				}
				else{
					//send(userSock[1], buffer,my_strlen(buffer),0);
					for(int i=0;i<numUsers;i++){
						int sockBOYO=userSock[i];
						if (sockBOYO!=sockBOIIIII){
							send(sockBOYO, buffer,my_strlen(buffer),0);
						}
					}
				}
   		// user=accept(sockBOIIIII, (struct sockaddr*)&socketAddress, &addr_size);
    	// if(user<0){
    	// 	my_str("accept error lol");
    	// 	exit(1);
    	// }
    	// my_str("Connection accepted from IP: unknown");
    	// //my_str(socketAddress.sin_addr);
    	// my_str(" port : ");
     //  	my_int(ntohs(socketAddress.sin_port));
     //  	my_str("\n");
     //  	recv(user, buffer,2048,0);
     //  	if(my_strncmp(buffer,"/exit",5)==0){
     //  		my_str("User is exitting");
     //  	}
     //  	else{
     //  		my_str("Client said: ");
     //  		my_str(buffer);
     //  		send(user,buffer,my_strlen(buffer),0);
     //  		memset(buffer, '\0', (sizeof buffer));
     //  	}
    	// //userPos=userPos+1;
    	
    }
    my_str("it gets here");
	return 0;
}
*/
//code kind of works better lets go for gold
/*
int main(int argc, char* argv[]){
	//version 2.1 kind of working lets try for gold boys
	if (argc < 2){
		perror("Usage error");
		exit(1);
	}
	int numUsers=0;
	int userSock[2048];
	memset(&userSock, 0, sizeof(userSock));
	fd_set readfds;
	int bindVar;
	//int user[1024];
	char buffer[2048];
	int user;
	socklen_t addr_size;
	//int userPos=0;
	//char message[1024]="server has been reached";
	int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketAddress;
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[1]));
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    bindVar=bind(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)));
    if(bindVar<0){
    	my_str("Binding error lol\n");
    	exit(0);
    }
    if(listen(sockBOIIIII, 1024)==0){
    	my_str("Listening boiiii\n");
    }
    else{
    	my_str("Listening error lol");
    }
    	FD_ZERO(&readfds);
    	FD_SET(sockBOIIIII, &readfds);
    	userSock[numUsers]=sockBOIIIII;
    	fd_set copy;
    	FD_ZERO(&copy);
    	FD_SET(sockBOIIIII, &copy);
    while(1){
    	//might have problems here double check dumbass
    	copy= readfds;
    	// FD_ZERO(&readfds);
    	// FD_SET(sockBOIIIII, &readfds);
    	// FD_ZERO(&copy);
    	// FD_SET(sockBOIIIII, &copy);
    	my_str("its repeating this too\n");
    	my_int(FD_SETSIZE);
		int selectTest=select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
		selectTest=select(FD_SETSIZE, &copy, NULL, NULL, NULL);
		if(selectTest<0){
			my_str("Sorry select machine broke\n");
			exit(0);
		}
		//my_str("PASSED SELECT");
		my_int(FD_SETSIZE);
		//for(int i =0; i<FD_SETSIZE;i++){
			//my_str("HERE");
			//int sock= userSock[i];
			if(FD_ISSET(sockBOIIIII,&readfds)){
				//if(sock==sockBOIIIII){
					user=accept(sockBOIIIII, (struct sockaddr*)&socketAddress, &addr_size);
					if(user<0){
						my_str("accepting error lol\n");
						exit(0);
					}
				//}if sock==sockboi
    			FD_SET(user, &readfds);
    			numUsers++;
    			my_str("Connection accepted from IP: ");
    			my_str(inet_ntoa(socketAddress.sin_addr));
    			my_str(" port : ");
     		  	my_int(ntohs(socketAddress.sin_port));
     			my_str("\n");
			}
			//else{
				//my_str("gethereWHY ARE YOU JUST REPEATING THE ELSE???");
				// memset(buffer, '\0', (sizeof buffer));
				// int testerooski=recv(sock, buffer,2048,0);
				// my_str(buffer);	
				// if(testerooski==0){
				// 	my_str("MOOOOOOOOOOOOOOO\n");
				// 	close(sock);
				// 	FD_CLR(sock, &readfds);
				// }
				// else{
				// 	send(userSock[1], buffer,my_strlen(buffer),0);
				// 	for(int i=0;i<numUsers;i++){
				// 		int sockBOYO=userSock[i];
				// 		if (sockBOYO!=sockBOIIIII){
				// 			send(sockBOYO, buffer,my_strlen(buffer),0);
				// 		}
				// 	}
				// }

			//}
		//}forloop
		memset(buffer, '\0', (sizeof buffer));
				int testerooski=recv(user, buffer,2048,0);
				my_str(buffer);	
				my_int(testerooski);
				send(user, buffer,my_strlen(buffer),0);
				if(testerooski==0){
					my_str("MOOOOOOOOOOOOOOO\n");
					close(user);
					FD_CLR(user, &readfds);
				}
				else{
					//send(userSock[1], buffer,my_strlen(buffer),0);
					for(int i=0;i<numUsers;i++){
						int sockBOYO=userSock[i];
						if (sockBOYO!=sockBOIIIII){
							send(sockBOYO, buffer,my_strlen(buffer),0);
						}
					}
				}
   		// user=accept(sockBOIIIII, (struct sockaddr*)&socketAddress, &addr_size);
    	// if(user<0){
    	// 	my_str("accept error lol");
    	// 	exit(1);
    	// }
    	// my_str("Connection accepted from IP: unknown");
    	// //my_str(socketAddress.sin_addr);
    	// my_str(" port : ");
     //  	my_int(ntohs(socketAddress.sin_port));
     //  	my_str("\n");
     //  	recv(user, buffer,2048,0);
     //  	if(my_strncmp(buffer,"/exit",5)==0){
     //  		my_str("User is exitting");
     //  	}
     //  	else{
     //  		my_str("Client said: ");
     //  		my_str(buffer);
     //  		send(user,buffer,my_strlen(buffer),0);
     //  		memset(buffer, '\0', (sizeof buffer));
     //  	}
    	// //userPos=userPos+1;
    	
    }
    my_str("it gets here");
	return 0;
}
*/
//CODE KIND OF WORKS. SAVING INCASE YA BOY BREAKS THIS BY ADDING JUNK
/*int main(int argc, char* argv[]){
	//version 2.0
	if (argc < 2){
		perror("Usage error");
		exit(1);
	}
	int bindVar;
	//int user[1024];
	char buffer[1024];
	int user;
	socklen_t addr_size;
	//int userPos=0;
	//char message[1024]="server has been reached";
	int sockBOIIIII;
    sockBOIIIII= socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketAddress;
    memset(&socketAddress, '\0', sizeof(socketAddress));
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(my_atoi(argv[1]));
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    bindVar=bind(sockBOIIIII,(struct sockaddr *) &socketAddress, (sizeof(socketAddress)));
    if(bindVar<0){
    	my_str("Binding error lol\n");
    	exit(0);
    }
    if(listen(sockBOIIIII, 1024)==0){
    	my_str("Listening boiiii\n");
    }
    else{
    	my_str("Listening error lol");
    }
    while(1){
   		user=accept(sockBOIIIII, (struct sockaddr*)&socketAddress, &addr_size);
    	if(user<0){
    		exit(1);
    	}
    	my_str("Connection accepted from IP: unknown");
    	//my_str(socketAddress.sin_addr);
    	my_str(" port : ");
      	my_int(ntohs(socketAddress.sin_port));
      	my_str("\n");
      	recv(user, buffer,1024,0);
      	if(my_strncmp(buffer,"/exit",5)==0){
      		my_str("User is exitting");
      	}
      	else{
      		my_str("Client said: ");
      		my_str(buffer);
      		send(user,buffer,my_strlen(buffer),0);
      		memset(buffer, '\0', (sizeof buffer));
      	}
    	//userPos=userPos+1;
    	
    }
    my_str("it gets here");
	return 0;
}*/ 