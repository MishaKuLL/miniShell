
#include "parser.h"

int	get_redir_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("<>", str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i] && !ft_strchr("<> ", str[i]))
		i++;
	return (i);
}

int	parse_redir(t_cmd *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd->input[i])
	{	
		if (ft_strchr("\'\"", cmd->input[i]))
			skip_quotes_int(cmd->input, &i);
		if (ft_strchr("<>", cmd->input[i]))
		{
			tmp = ft_substr(&cmd->input[i], 0, get_redir_len(&cmd->input[i]));
			if (put_redir(cmd, tmp))
				return (1);
			ft_memset(cmd->input + i, '\6', get_redir_len(&cmd->input[i]));
			i += get_redir_len(&cmd->input[i]);
		}
		else if (cmd->input[i])
			++i;
	}
	cmd->input = ft_str_translate(cmd->input, '\6', '\0');
	return (0);
}
