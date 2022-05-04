/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:52 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/05/04 18:12:00 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*x;
	int		i;
	int		ind;

	if (!s1)
		return (NULL);
	x = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!x)
		return (NULL);
	i = 0;
	ind = 0;
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[ind])
	{
		x[i] = s2[ind];
		i++;
		ind++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*x;
	int		i;

	x = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!x)
		return (0);
	i = 0;
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*x;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (len > i)
		x = (char *)malloc((i + 1) * sizeof(char));
	else
		x = (char *)malloc((len + 1) * sizeof(char));
	if (!x)
		return (NULL);
	if (start > i)
		return (x);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		x[i] = s[i + start];
		i++;
	}
	x[i] = '\0';
	return (x);
}
