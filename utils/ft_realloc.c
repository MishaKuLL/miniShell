/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 21:48:59 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_realloc(char *str, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res)
	{
		while (str && str[i])
		{
			res[i] = str[i];
			i++;
		}
		while (i <= len)
		{
			res[i] = '\0';
			i++;
		}
		free(str);
	}
	return (res);
}
