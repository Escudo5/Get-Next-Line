/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:14:24 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/09 11:41:29 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
static char	*ft_strcat(char *dest, const char *src, int size);
char	*realloc_line_frag(char *line_frag, int new_size, int old_size);
char	*ft_strlcpy(char *dest, const char *src, size_t size);

#endif
#endif