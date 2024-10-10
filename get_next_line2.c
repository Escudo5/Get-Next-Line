/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/10 16:43:46 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




static int	malloc_line_frag(char **line, int *line_frag_size_now,
		int *line_frag_total_size, int size_i_read_at_a_time)
{
	*line_frag = malloc(size_i_read_at_a_time);
	if (!line_frag)
		return (0);
	*line_frag_size_now = 0;
	*line_frag_total_size = size_i_read_at_a_time;
	return (1);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		b_read;
	char	*line;
	int	i;
	char *temp;

	line = NULL;
	while (1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == 0)
			return (NULL);
		if (b_read == -1)
			return;
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		break;
	}
	i++;		
	if (line == NULL)
		line = strdup(buffer);
	else 
	{
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	




	
		{
			if (!malloc_line_frag(&line_frag, &line_frag_size_now,
					&line_frag_total_size, BUFFER_SIZE))
				return (NULL);
		}
		
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
