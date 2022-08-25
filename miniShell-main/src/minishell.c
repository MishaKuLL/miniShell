#include "../inc/minishell.h"

void print_prompt1(void);
void print_prompt2(void);

int main(int argc, char **argv)
{
	// char *cmd;
    t_data  data;

    (void) argc;
    (void) argv;
	while (1)
	{
		print_prompt1();
		// cmd = read_cmd(cmd);
		// if (!cmd)
		// {
		// 	exit(EXIT_SUCCESS);
		// }
		// if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		// {
		// 	free(cmd);
		// 	continue;
		// }
		// if (strcmp(cmd, "exit") == 0)
		// {
		// 	free(cmd);
		// 	break ;
		// }
		// write(1, cmd, ft_strlen(cmd));
		// write(1, "\n", 1);
		// free(cmd);
	}
    free_data(&data, NULL, 0);
	exit(EXIT_SUCCESS);   
}

void print_prompt1(void)
{
   fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
   fprintf(stderr, "> ");
} 