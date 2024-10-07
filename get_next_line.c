/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/07 17:38:16 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		b_read;
	char	*line_frag;
	int		i;
	int		size_ini;

	size_ini = BUFFER_SIZE;
	line_frag = NULL;
	while (true)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == 0)
			return (NULL);
		if (b_read == -1)
			return (NULL);
		i = 0;
		if (line_frag == NULL)
		{
			line_frag = malloc(size_ini);
			if (line_frag == NULL)
				return (NULL);
		}
		while (i < b_read)
		{
			ft_strlcpy(line_frag, buffer, size_ini);
			if (buffer[i] == '\n')
			
				return ;
		}
	}
}

static char	*ft_strcat(char *dest, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < size && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
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

char	*ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	if (size == 0)
		;
	return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (strlen(src));
}