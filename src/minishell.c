#include "../inc/minishell.h"

static void	initialize(t_struct *data);

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

static void	initialize(t_struct *data)
{
	data->has_flag = 0;
	data->num_tokens = 0;
	data->quote = NULL;
	data->line = (char *) NULL;
	data->line_read = (char *) NULL;
	data->name_file = 0;
	data->error_name_file = (char *) NULL;
	data->home = (char *) NULL;
	data->tokens = (char **) NULL;
	data->cmd = (char *) NULL;
	data->last_redir = 0;
	data->is_append = 0;
	data->out_fd = 0;
	data->in_fd = 0;
	data->c = 0;
	g_ret_number = 0;
}
