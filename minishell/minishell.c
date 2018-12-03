#define _POSIX_SOURCE
#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

pid_t child;
pid_t parent;
char* file;
void controlC(int sig){
	if(child!=-2){
		kill(child, SIGUSR1);
	}
	else{
		my_str("\n");
		my_str("Minishell: ");
		my_str(file);
		my_str(" $: ");

	}
}

void ex(){
    exit(0);
}

int main(){
	file=getcwd(NULL,0);
	while(1){
		signal(SIGUSR1,SIG_IGN);
		signal(SIGINT, controlC);
		my_str("Minishell: ");
		my_str(file);
		my_str(" $: ");
		char buff[2048];
		char c;
		child=-2;
		for( int i = 0; i<2048; i++){
			if(read(STDIN_FILENO, &c, 1)==1){
				if(c=='\n'||c=='\0'){
					buff[i]='\0';
					break;
				}
				else{
					buff[i]=c;
				}
			}
			else
				break;
			}
		buff[2048]='\0';
		char** input=my_str2vect(buff);
		int error=0;
		char* cmd=input[0];
		if(cmd==NULL) continue;
		else if(my_strcmp(cmd, "cd")==0){
			free(file);
			error=chdir(input[1]);
			file=getcwd(NULL,0);
			if(my_strcmp(input[1], NULL) ==0 || my_strcmp(input[1], "~") == 0){
                    (void)chdir(getenv("HOME"));
                    file=getcwd(NULL,0);
                }
                else if((chdir(input[1]) == 0)){ }
                else if(error !=0){
					//my_str("\n");
					my_str(input[1]);
					my_str(" does not exist.");
					my_str("\n");
				}
            }
		else if(my_strcmp(cmd,"exit")==0){
			my_str("Exiting\n");
			exit(0);
		}
		else if(my_strcmp(cmd, "help")==0){
			my_str("Exit using the command exit.\nChange directory using the command cd filepath.\nGet help using the command help.\n");	
		}
		else if(my_strcmp(cmd, "") == 0){}
		else{
			child=fork();
			if(child < 0){
				my_str("Fork error\n");
				exit(1);
			}
			if(child>0){
				wait(NULL);
			}
			else{
				signal(SIGINT,SIG_IGN);
                signal(SIGUSR1, ex);
				if(execvp(input[0], input)!=0){
					my_str("Not a valid input \n");
					exit(0);
				}
			}

		}
	}
	return 0;
}

/*
#define _POSIX_SOURCE
#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

pid_t child;
pid_t parent;

void controlC(int sig){
	my_str("\n");
	if(child!=-2){
		kill(child, SIGUSR1);
	}
}

void exit(int sig){
    exit(0);
}

int main(){
	char* file;
	file=getcwd(NULL,0);
	signal(SIGUSR1,SIG_IGN);
	signal(SIGINT, controlC);
	while(1){
		my_str("Minishell: ");
		my_str(file);
		my_str(" $: ");
		char buff[255];
		char c;
		child=-2;
		for(int i = 0; i<255; i++){
			if(read(STDIN_FILENO, &c, 1)==1){
				if(c=='\n'||c=='\0'){
					buff[i]='\0';
					break;
				}
				else{
					buff[i]=c;
				}
			}
			else
				break;
			}
		buff[255]='\0';
		char** input=my_str2vect(buff);
		int error=0;
		char* cmd=input[0];
		if(cmd==NULL) continue;
		else if(my_strcmp(cmd, "cd")==0){
			free(file);
			error=chdir(input[1]);
			file=getcwd(NULL,0);
			if(error !=0){
				//my_str("\n");
				my_str(input[1]);
				my_str(" does not exist.");
				my_str("\n");
			}
		}
		else if(my_strcmp(cmd,"exit")==0){
			my_str("Exitting\n");
			exit(0);
		}
		else if(my_strcmp(cmd, "help")==0){
			my_str("Exit using the command exit.\nChange directory using the command cd filepath.\nGet help using the command help.\n");	
		}
		else{
			child=fork();
			if(child < 0){
				my_str("Fork error\n");
				exit(1);
			}
			if(child>0){
				wait(NULL);
			}
			else{
				signal(SIGINT,SIG_IGN);
                signal(SIGUSR1, exit);
				if(execvp(input[0], input)!=0){
					my_str("Not a valid input \n");
					exit(0);
				}
				wait(NULL);
			}

		}
	}
}

*/