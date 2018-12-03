#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>

char* cypher(char* m){
	int key=1;
	char* c=my_strdup(m);
	int l= my_strlen(c);
	for(int i=0;i<l;i++){
			//if (c[i] = '!' || ' '){}
			if(!((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))){}
			else{
				for (int j = 0; j < key; j++) {
					c[i] += 1;
					if (c[i] == 'z'+1)
						c[i] = 'a';
					else if (c[i] == 'Z'+1)
						c[i] = 'A';
				}
			}
		}
		return c;
}

int main(int argc, char **argv){
	if(argc<=1){
		my_str("nothing entered\n");
		return 0;
	}
	else{
	char** vect=&argv[1];
	char* str=my_vect2str(vect);
	int fd[2];//parent to child pipe
	int fd2[2];//child to grandchild pipe
	pipe(fd);
	pipe(fd2);
	pid_t pid=fork();
	if(pid<0){
		my_str("error with the fork");
		exit(1);
	}
	if(pid>0){
		close(fd[0]);
		write(fd[1],str,500);//parent to child communication
		my_str("parent: ");
		my_str(str);
		my_str("\n");
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else if(pid==0){
		pid=fork();
		if(pid<0){
		my_str("error with the fork");
		exit(1);
	}
		if(pid>0){
			close(fd[1]);
			read(fd[0], str, 500);// parent to child communication
			char* str2=cypher(str);
			my_str("child: ");
			my_str(str2);
			my_str("\n");
			close(fd2[0]);
			write(fd2[1],str,500);//child to grandchild communications
			wait(NULL);
			wait(NULL);
		}
		else {
			close(fd2[1]);
			read(fd2[0], str, 500);//child to grandchild communications
			my_str("grandchild: ");
			my_revstr(str);
			my_str(str);
			my_str("\n");
			wait(NULL);
			(void)exit(1);
		}
	}

	return 0;
	}	
}
