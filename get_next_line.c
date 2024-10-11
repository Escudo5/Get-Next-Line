/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/11 11:12:13 by escudo5          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line = ft_strdup(buffer);
}



