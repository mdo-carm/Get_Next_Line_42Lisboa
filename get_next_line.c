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

char	*final_output(char **output)
{
	char	*final_output;
	char	*temp;

	if (!*output || !**output != '\0')
		return (NULL);
	temp = ft_strdup(*output);
	if (ft_strchr(*output, '\n') != 0)
	{
		temp = ft_strchr(temp, '\n');
		temp++;
		final_output = ft_substr(*output, 0, ft_strlen(*output) - ft_strlen(temp));
		free(*output);
		*output = ft_strdup(temp);
		printf("|%s|", final_output);
		return (final_output);
	}
	final_output = ft_substr(*output, 0, ft_strlen(*output));
	printf("|%s|", final_output);
	free(*output);
	return (final_output);
}

char	*get_next_line(int fd)
{
	static char	*output[FOPEN_MAX];
	char		*temp_buf;
	int			read_output;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	temp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	read_output = read(fd, temp_buf, BUFFER_SIZE);
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
