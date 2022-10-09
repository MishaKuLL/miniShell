/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:26:38 by asherlin          #+#    #+#             */
/*   Updated: 2022/10/04 21:49:00 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*check(const char *big, const char *little, size_t size)
{
	char	*start;
	size_t	i;

	start = (char *)big;
	i = 0;
	while (*little)
	{
		if (*big != *little || i == size)
			return (NULL);
		i++;
		big++;
		little++;
	}
	return (start);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*start;
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (*big && i < len)
	{
		if (*big == *little)
		{
			start = check(big, little, len - i);
			if (start)
				return (start);
		}
		big++;
		i++;
	}
	return (NULL);
}
