#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include "my.h"

typedef struct disp{
	int check, length;
	char* name;
}* FileDisplay;
FileDisplay filethrough(char* name){
	FileDisplay fd = (FileDisplay) malloc(sizeof(struct disp));
	fd->length = my_strlen(name);
	fd->name = name;
	fd->check = 0;
	return fd;
}
static FileDisplay* files;
static int w, h, i, highlight, wsize;
void display(){
	struct winsize ws;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	w = ws.ws_col;
	h = ws.ws_row;
}
int table(){
	clear();
	int termCols = 0;
	for(i = 0; i<wsize; i++){
		if(i==highlight){
			attron(A_UNDERLINE);
		}
		if(files[i]->length > termCols){
			termCols = files[i]->length;
		}
		if(getcurx(stdscr)>w-(files[i]->length)-1){
			return 1;
		}
		if(files[i]->check){
			attroff(COLOR_PAIR(2));
			attron(COLOR_PAIR(1));
		}
		addstr(files[i]->name);
		move(getcury(stdscr),getcurx(stdscr)-(files[i]->length));
		attroff(A_UNDERLINE);
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(2));
		if(1+getcury(stdscr)>=h){
			int x = getcurx(stdscr);
			if(i!=wsize-1 && x+termCols+2>w){
				return 1;
			}
			move(0,termCols+x+1);
			termCols = 0;
		}
		else{
			move(getcury(stdscr)+1,getcurx(stdscr));
		}
	}
	return 0;
}
int main(int argc, char* argv[]){
	FILE *fp;
	if(argc<2){
		perror("Error, files needed");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("Error");
		exit(1);
	}
	wsize=0;
	files = (FileDisplay*) malloc(sizeof(struct disp)*(argc-1));
	for(i = 1; i<argc; i++){
		files[i-1] = filethrough(argv[i]);
		wsize++;
	}
	initscr();
	raw();
	noecho();
	curs_set(0);
	keypad(stdscr,true);
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_GREEN);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	display();
	if(table()==1){
		clear();
		addstr("Please resize the window!");
	}
	while(1){
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		int ch = getch();
		if(ch == 27){
			endwin();
			exit(1);
		}
		if(ch == 10){
			endwin();
			//my_str("you pressed enter. bitch\n");
			for(int i = 0; i<wsize; i++){
				if(files[i]->check){
					my_str(files[i]->name);
					my_str(" ");
				}
			}
			my_str("\n");
			exit(1);
		}
		if(ch == ' '){ //highlight
			if(files[highlight]->check){
				files[highlight]->check = 0;
			}
			else{ //unhighlight
				files[highlight]->check = 1;
				if(highlight>=wsize-1){
					highlight=0;
				}
				else{
					highlight++;
				}
			}
		}
		if(ch == KEY_RIGHT){
			if(highlight>=wsize-h-1){
				highlight=wsize-1;
			}
			else{
				highlight += h;
			}

		}
		if(ch == KEY_LEFT){
			if(highlight < h){
				highlight = 0;
			}
			else{
				highlight -= h;
			}
		}
		if(ch == KEY_UP){
			if(highlight%h == 0){
				highlight+=h-1;
				if(highlight>=wsize){
					highlight = wsize-1;
				}
			}
			else{
				highlight--;
				if(highlight<0){
					highlight=wsize-1;
				}
			}
		}
		if(ch == KEY_DOWN){
			highlight++;
			if(highlight%h==0){
				highlight-=h;
			}
			if(highlight>=wsize){
				highlight-=(highlight%h);
			}
		}
		if(ch == KEY_RESIZE){
			display();
			//endwin();
			//my_str("you fucking resized. bitch\n");
			//exit(1);
		}
		if(table()==1){
			clear();
			addstr("Resize window and try again.");
		}
	}
	endwin();
}
