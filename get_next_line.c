/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/04/26 21:58:59 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> 

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	return (x);
}

char	*final_output(char **output)
{
	char	*final_output;
	char	*temp;

	temp = ft_strdup(*output);
	if (ft_strchr(*output, '\n') > 0)
	{
		temp = ft_strchr(*output, '\n');
		temp++;
		final_output = ft_substr(*output, 0, ft_strlen(*output) - ft_strlen(temp));
		free(*output);
		*output = ft_strdup(temp);
		printf("%s", final_output);
		return (final_output);
	}
	free(*output);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*output[OPEN_MAX];
	char		*temp_buf;
	int			read_output;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	temp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	read_output = read(fd, temp_buf, BUFFER_SIZE);
	if (read_output == 0)
		return (NULL);
	if (!output[fd])
		output[fd] = ft_strdup("");
	while (read_output > 0)
	{
		temp_buf[read_output] = '\0';
		output[fd] = ft_strjoin(output[fd], temp_buf);
		if (ft_strchr(output[fd], '\n') != 0)
			break ;
		read_output = read(fd, temp_buf, BUFFER_SIZE);
	}
	free(temp_buf);
	return (final_output(&output[fd]));
}

int	main()
{
	int fd = open("text.txt", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
