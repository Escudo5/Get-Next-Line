/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/11 11:01:32 by escudo5          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	malloc_line_frag(char **line, int *line_frag_size_now,
		int *line_frag_total_size, int size_i_read_at_a_time)
{
	*line = malloc(BUFFER_SIZE);
	if (!line)
		return (0);
	*line_frag_size_now = 0;
	*line_frag_total_size = size_i_read_at_a_time;
	return (1);
}

char	*get_next_line(int fd)
{
	static char *remain;
	char	buffer[BUFFER_SIZE];
	int		b_read;
	char	*line;
	int	i;
	char *temp;
	line = NULL;

	if (remain)
		line = ft_strdup(remain);
			free(remain);
	remain = NULL;
	while (b_read = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line =append_buffer(line, buffer, b_read, &remain);
		if (remain)
			return (line);
	}
	if (b_read == 0 && line)
	{
		return (line);
		return (NULL);
	}
	if (line == NULL)
		line = strdup(buffer);
}



char	*append_buffer(char	*line, char	*buffer, int b_read, char **remain)
{
	int i;
	char	*temp;

	i = 0;
	while (i < b_read)
	{
		if (buffer[i] == '\n')
		{
			temp = ft_strjoin(line, ft_substr(buffer, 0, i + 1));
			free(line);
			line = temp;
			*remain = ft_strdup(&buffer[i + 1]);
			return (line);
		}
		i++;
	}
	if (line == NULL)
		line = ft_strdup(line, buffer);
	else 
	{
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	return (line);
}
char	*realloc_line_frag(char *line, int new_size, int old_size)
{
	char	*new_line;
	int		i;

	new_line = malloc(new_size);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_line[i] = line_frag[i];
		i++;
	}
	new_line[i] = '\0';
	free(line_frag);
	return (new_line);
}
