/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/16 10:57:12 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char *line, char *buffer, int b_read, char **remain)
{
	int		i;
	char	*temp;
	char	*substring;

	i = 0;
	while (i < b_read)
	{
		if (buffer[i] == '\n')
		{
			substring = ft_substr(buffer, 0, i + 1);
			temp = ft_strjoin(line, substring);
			free(line);
			free(substring);
			line = temp;
			free(*remain);
			if (i + 1 < b_read)
				*remain = ft_strdup(&buffer[i + 1]);
			else
				*remain = NULL;
			return (line);
		}
		i++;
	}
	if (line == NULL)
		line = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		buffer[BUFFER_SIZE + 1];
	int			b_read;
	char		*line;

	line = NULL;
	if (remain)
	{
		line = ft_strdup(remain);
		free(remain);
		remain = NULL;
	}
	b_read = read(fd, buffer, BUFFER_SIZE);
	while ((b_read) > 0)
	{
		buffer[b_read] = '\0';
		line = append_buffer(line, buffer, b_read, &remain);
		if (remain)
			return (line);
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_read < 0)
		free(line);
	return (NULL);
	if (line)
		return (line);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("chistes.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error abriendo el archivo");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line); // Sin "\n".
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
