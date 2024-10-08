/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/08 16:56:05 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		b_read;
	char	*line_frag;
	int		i;
	int		size_i_read_at_a_time;
	int		line_frag_size_now;
	int		new_size_line_frag;
	int		old_size_line_frag;
	int		line_frag_total_size;

	size_i_read_at_a_time = BUFFER_SIZE;
	line_frag = NULL;
	while (1)
	{
		b_read = read(fd, buffer, size_i_read_at_a_time);
		if (b_read == 0)
			return (NULL);
		if (b_read == -1)
			return (NULL);
		i = 0;
		if (line_frag == NULL)
		{
			line_frag = malloc(size_i_read_at_a_time);
			if (line_frag == NULL)
				return (NULL);
			line_frag_size_now = 0;
			line_frag_total_size = size_i_read_at_a_time;
		}
		next_line_frag(**line_frag, char *buffer, int *line_frag_size_now,
			int b_read);
	}
}

char	*realloc_line_frag(char *line_frag, int new_size, int old_size)
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

void	next_line_frag(char **line_frag, char *buffer, int *line_frag_size_now,
		int b_read)
{
	int	i;

	i = 0;
	while (i < b_read)
	{
		if (line_frag_size_now + 1 > line_frag_total_size)
		{
			*line_frag = realloc_line_frag(*line_frag, *new_size_line_frag,
					*line_size_frag_now);
			if (!line_frag)
				return ;
		}
		(*line_frag)[*line_frag_size_now] = buffer[i];
		// Agrega el carácter al final de line_frag
		(*line_frag_size_now)++;
		// Incrementa el tamaño actual
		if (buffer[i] == '\n')
		{
			(*line_frag)[*line_frag_size_now] = '\0';
			return ; // Termina la función
		}
		i++; // Incrementa el índice
	}
}
