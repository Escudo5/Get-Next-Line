/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/09 16:01:01 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	next_line_frag(char **line_frag, char *buffer,
		int *line_frag_size_now, int b_read, int *line_frag_total_size,
		int size_i_read_at_a_time)
{
	int	i;

	i = 0;
	while (i < b_read)
	{
		if ((*line_frag_size_now) + 1 > *line_frag_total_size)
		{
			*line_frag_total_size += size_i_read_at_a_time;
			*line_frag = realloc_line_frag(*line_frag, *line_frag_total_size,
					*line_frag_size_now);
			if (!*line_frag)
				return ;
		}
		(*line_frag)[*line_frag_size_now] = buffer[i];
		(*line_frag_size_now)++;
		if (buffer[i] == '\n')
		{
			(*line_frag)[*line_frag_size_now] = '\0';
			return ;
		}
		i++;
	}
}

static int	initialize_line_frag(char **line_frag, int *line_frag_size_now,
		int *line_frag_total_size, int size_i_read_at_a_time)
{
	*line_frag = malloc(size_i_read_at_a_time);
	if (!line_frag)
		return (0);
	line_frag_size_now = 0;
	line_frag_total_size = size_i_read_at_a_time;
	return (1);
}

char	*get_next_line(int fd)
{
	char	buffer[42];
	int		b_read;
	char	*line_frag;
	int		size_i_read_at_a_time;
	int		line_frag_size_now;
	int		line_frag_total_size;

	size_i_read_at_a_time = 42;
	line_frag = NULL;
	while (1)
	{
		b_read = read(fd, buffer, size_i_read_at_a_time);
		if (b_read == 0 || b_read == -1)
			return (NULL);
		if (line_frag == NULL)
		{
			initialize_line_frag(&line_frag, &line_frag_size_now,
				&line_frag_total_size, &size_i_read_at_a_time)
		}
		next_line_frag(&line_frag, buffer, &line_frag_size_now, b_read,
			&line_frag_total_size, size_i_read_at_a_time);
	}
}

static char	*realloc_line_frag(char *line_frag, int new_size, int old_size)
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
