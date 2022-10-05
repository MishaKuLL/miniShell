/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 21:48:59 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_double_realloc(char **str, int len, char *line)
{
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (res)
	{
		if (str)
		{
			while (str[i])
			{
				res[i] = ft_strdup(str[i]);
				i++;
			}
		}
		if (line)
			res[i] = ft_strdup(line);
		else
			res[i] = NULL;
		res[i + 1] = NULL;
		free_arr(str);
	}
	return (res);
}
