#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFSZ 128

static int song;

void play_ed_sheeran(){
	printf("\nInstead\nPlaying Perfect\n");
}

void play_eminem(){
	printf("\nInstead\nPlaying Lucky You\n");
}

void play_music(int l) {
	char *buf[l];
	char bu[1024];

	printf("Which music you want to play:\n");
	fgets(bu, 1024, stdin);
	printf("\nYou want to play:\n");
	printf(bu);
	printf("\nStack at %p\n", buf);

	if (song == 26) {
		play_eminem();
	} else {
		play_ed_sheeran();
	}
}

int main(int argc, char** argv) {
	
	if (argc < 2) {
                fprintf(stderr, "Missing arguments\n");
                fprintf(stderr, "Usage: %s <student_id>\n", argv[0]);
                return EXIT_FAILURE;
        }

	srand(atoi(argv[1]));
        song = rand();
	int l = (rand() % MAX_BUFSZ) + 1;

	play_music(l);
	return EXIT_SUCCESS;
}
