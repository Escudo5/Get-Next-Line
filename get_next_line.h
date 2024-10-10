/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:14:24 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/10 16:38:50 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

static char	*realloc_line_frag(char *line_frag, int new_size, int old_size);

static int	malloc_line_frag(char **line_frag, int *line_frag_size_now,
				int *line_frag_total_size, int size_i_read_at_a_time);





#endif