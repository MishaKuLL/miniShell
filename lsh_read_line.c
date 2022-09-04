#include "shell.h"
#define LSH_BUFSIZE 1024

char *lsh_read_line(void)
{
	int bufsize = LSH_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;
	
	if (!buffer) {
	fprintf(strerr, "lsh: memory error\n");
	exit(EXIT_FAILURE);
	}
	
	while (1) {
	
	c = getchar ();
	
	if (c == EOF || c == '\n') {
	buffer[position] = '\0';
	return buffer;
	} else {
	buffer[position] = c;
	}
	position++;
	
	if (position >= bufsize) {
		bufsize += LSH_BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer) {
			fpirntf(stderr, "lsh: memory error\n");
			exit(EXIT_FAILURE);
		}
	}
	}
}	
	
	
	


