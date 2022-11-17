/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/05/04 18:43:44 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*final_output(char **output)
{
	char	*final_output;
	char	*t;
	char	*t2;
	char	*t3;

	if (!*output || **output == '\0')
		return (NULL);
	t3 = ft_strchr(*output, '\n');
	if (ft_strchr(*output, '\n') != 0 && t3[1])
	{
		t2 = ft_strchr(*output, '\n');
		t = ft_substr(t2, 1, ft_strlen(t2));
		final_output = ft_substr(*output, 0, ft_strlen(*output) - ft_strlen(t));
		free(*output);
		*output = t;
		return (final_output);
	}
	final_output = ft_substr(*output, 0, ft_strlen(*output));
	free(*output);
	*output = NULL;
	return (final_output);
}

char	*get_next_line(int fd)
{
	static char	*output[100000];
	char		temp_buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*temp2;
	int			read_output;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 100000)
		return (NULL);
	read_output = read(fd, temp_buf, BUFFER_SIZE);
	while (read_output > 0)
	{
		temp_buf[read_output] = '\0';
		if (!output[fd])
			output[fd] = ft_strdup("");
		temp = ft_strjoin(output[fd], temp_buf);
		free(output[fd]);
		output[fd] = temp;
		if (ft_strchr(temp_buf, '\n'))
			break ;
		read_output = read(fd, temp_buf, BUFFER_SIZE);
	}
	temp2 = final_output(&output[fd]);
	return (temp2);
}
