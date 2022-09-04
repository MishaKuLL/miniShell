#include "shell.h"
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM "\t\n\r\a"

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char));
	char *token;
	if (!tokens) {
		fprintf(stderr, "lsh: memory error");
		exit(EXIT_FAILURE);
	}
	
	token = str_tok(line, LSH_TOK_DELIM);
	while (token != NULL) {
	tokens[position] = token;
	position++;
	
	if (position >= bufsize) {
	bufsize += LSH_TOK_BUFSIZE;
	tokens = realloc(tokens, bufsize * sizeof(char*));
	if (!tokens) {
		fprintf(stderr, "lsh: memory error");
		exit(EXIT_FAILURE);
	}
	
	token = str_tok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}	