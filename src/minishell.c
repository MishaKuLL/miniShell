#include "../inc/minishell.h"

int	main(void)
{
	t_struct	data;

	initialize(&data);
	while (1)
	{
		data.out_fd = STDOUT_FILENO;
		data.in_fd = STDIN_FILENO;
		get_line(&data);
		if (data.line_read)
		{
			if (ft_strlen(data.line_read) != 0)
			{
				split_cmd(&data, data.line_read, 0);
				if (data.split.n_comand > 0 && data.commands[0][0] != '|')
					run_commands(&data);
				if (data.commands[0] && data.commands[0][0] == '|')
					printf(ERROR_PIPE);
				free_char_array2(data.commands);
			}
			free(data.line_read);
		}
		else
			run_signals(3);
	}
}

void print_prompt1(void)
{
   fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
   fprintf(stderr, "> ");
}

char	*read_cmd(char *buf)
{
	int		buflen;
	char	*tmp;

	get_next_line(0, &buf);
	buflen = ft_strlen(buf);
	while (buflen > 1 && buf[buflen - 1] == '\\')
	{
		buf[buflen - 1] = '\n';
		buf[buflen] = '\0';
		print_prompt2();
		tmp = buf;
		get_next_line(0, &buf);
		buf = ft_strjoin(tmp, buf);
		buflen = ft_strlen(buf);
	}
	return (buf);
}

 void	initialize(t_struct *data)
{
	data->last_redir = 0;
	g_ret_number = 0;
	data->tokens = (char **) NULL;
	
}



