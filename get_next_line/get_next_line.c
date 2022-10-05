/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:01:54 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/05 20:13:21 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ctrl_d(char *remainder)
{
	if (remainder[0] == 0)
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	else
		write(0, "  \b\b", 4);
	return (1);
}

int	cut_line(char **line, char **remainder)
{
	int		i;

	i = 0;
	while ((*remainder)[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(*line))
		return (-1);
	ft_strlcpy(*line, *remainder, i + 1);
	return (0);
}

int	read_line(char **remainder, char **line)
{
	int		ret;
	char	*buf;
	int		res;
	char	*tmp;

	ret = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (buf[0] != '\n' && ret != 0)
	{
		ret = read(0, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = *remainder;
		*remainder = ft_strjoin(*remainder, buf);
		if (!(*remainder))
			return (-1);
		free(tmp);
		if (ret == 0)
			ret = ctrl_d(*remainder);
	}
	free(buf);
	res = cut_line(line, remainder);
	return (res);
}

int	get_next_line(char **line)
{
	int				out;
	char			*remainder;

	if (!line)
		return (-1);
	remainder = ft_strdup("");
	out = read_line(&remainder, line);
	free(remainder);
	return (out);
}
