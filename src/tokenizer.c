#include "../inc/minishell.h"

int	tokenizer_find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle || string[i] == D_QUOTE || string[i] == QUOTE)
			return (i);
		if (string[i] == '?')
			return (i + 1);
		i++;
	}
	return (i);
}

int	fixing_for_norminette(t_struct *data, char c, char *aux, int nbr)
{
	if (data->token.quote == 0 && (c == QUOTE || c == D_QUOTE))
		data->token.quote = c;
	else
	{
		if (data->token.quote == c)
			data->token.quote = 0;
		else
		{
			aux[nbr] = c;
			nbr++;
		}
	}
	return (nbr);
}

void	tokenizer_clean_quotes(t_struct *data, char *in, int i, int c)
{
	char	*aux;

	data->token.quote = 0;
	aux = ft_strtrim(in, " ");
	data->has_flag = false;
	if (in[0] == '-' && in[1] == 'n')
	{
		data->has_flag = true;
		i += 2;
	}
	while (in[i] == ' ')
		i++;
	while (in[i])
	{
		c = fixing_for_norminette(data, in[i], aux, c);
		i++;
	}
	aux[c] = '\0';
	free(data->token.to_print);
	data->token.to_print = aux;
}

void	tokenizer(t_struct *data)
{
	t_token	*tk;

	tk = init_tk();
	data->token.quote = 0;
	tk->end = ft_strdup("");
	if (data->line)
	{
		while ((int)ft_strlen(data->line) > tk->i)
		{
			if (data->token.quote == 0 && (data->line[tk->i] == QUOTE))
				data->token.quote = data->line[tk->i];
			else
			{
				if (data->token.quote == data->line[tk->i])
					data->token.quote = 0;
				if (data->line[tk->i] == '~' && data->token.quote == 0)
					get_home_sign(data, tk);
				else if (data->line[tk->i] == '$' && data->token.quote == 0)
					get_dollar_sign(data, tk);
			}
			tk->len++;
			tk->i++;
		}
		finish_tokenizer(data, tk);
	}
}
