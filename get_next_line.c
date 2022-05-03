/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:50 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/05/03 19:01:09 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*final_output(char **output)
{
	char	*final_output;
	char	*temp;

	if (!*output || **output == '\0')
		return (NULL);
	if (ft_strchr(*output, '\n') != 0)
	{
		temp = ft_strdup(*output);
		temp = ft_strchr(temp, '\n');
		temp++;
		final_output = ft_substr(*output, 0, ft_strlen(*output) - ft_strlen(temp));
		free(*output);
		if (ft_strlen(temp) > 0)
			*output = ft_strdup(temp);
		printf("|%s|", final_output); //
		return (final_output);
	}
	final_output = ft_substr(*output, 0, ft_strlen(*output));
	printf("|%s|", final_output); //
	free(*output);
	*output = NULL;
	return (final_output);
}

char	*get_next_line(int fd)
{
	static char	*output[OPEN_MAX];
	char		*temp_buf;
	char		*temp;
	int			read_output;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	temp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	read_output = read(fd, temp_buf, BUFFER_SIZE);
	if (output[fd] == NULL)
		output[fd] = "\0";
	while (read_output > 0)
	{
		temp_buf[read_output] = '\0';
		output[fd] = ft_strjoin(output[fd], temp_buf);
		if (ft_strchr(temp_buf, '\n'))
			break ;
		read_output = read(fd, temp_buf, BUFFER_SIZE);
	}
	free(temp_buf);
	temp_buf = NULL;
	temp_buf = final_output(&output[fd]);
	temp = temp_buf;
	free(temp_buf);
	return (temp);
}

int	main()
{
	int	fd;

	fd = open("43_no_nl", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
