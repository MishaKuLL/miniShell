/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 21:48:59 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (*s1)
	{
		join[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		join[i++] = *s2;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
