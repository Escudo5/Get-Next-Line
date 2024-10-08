/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:14:09 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/08 13:26:06 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	next_line_frag(char **line_frag, char *buffer, int *line_frag_size_now,
		int b_read) while (i < b_read)
{
	int	i;

	i = 0;
	while (i < b_read)
		if (line_frag_size_now + 1 > line_frag_total_size)
		{
			*line_frag = realloc_line_frag(*line_frag, *new_size_line_frag,
					*line_size_frag_now) if (!line_frag) return ;
		}
	(*line_frag)[*line_frag_size_now] = buffer[i];
		// Agrega el carácter al final de line_frag
	(*line_frag_size_now)++;                      
		// Incrementa el tamaño actual
	if (buffer[i] == '\n') // Si encuentra un salto de línea
	{
		(*line_frag)[*line_frag_size_now] = '\0'; // Termina la línea
		return ;                                   // Termina la función
	}
	i++; // Incrementa el índice
}

