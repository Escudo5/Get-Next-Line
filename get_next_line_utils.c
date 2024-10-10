/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:14:09 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/10 16:41:00 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;

	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	ft_memcpy(joined, s1, s1_len);
	ft_memcpy(joined + s1_len, s2, s2_len);
	joined[s1_len + s2_len] = '\0';
	return (joined);
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

/*char	*ft_strlcpy(char *dest, const char *src, size_t size)
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
	return (ft_strlen(src));
}
*/


