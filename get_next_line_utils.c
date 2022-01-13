/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuanena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:09:56 by sjuanena          #+#    #+#             */
/*   Updated: 2022/01/12 17:24:38 by sjuanena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*src;
	size_t	i;
	size_t	j;

	while (s1 != NULL && s2 != NULL)
	{
		src = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (src == NULL)
			return (0);
		i = ft_strlen(s1);
		j = 0;
		while (i > j)
		{
			src[j] = s1[j];
			j++;
		}
		i = 0;
		while (j < (ft_strlen(s1) + ft_strlen(s2)))
		{
			src[j++] = s2[i++];
		}
		src[j] = '\0';
		return (src);
	}
	return (0);
}

char	*ft_strchr(const char	*s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}
	if (s[i] == '\0')
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
