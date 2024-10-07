/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:12:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/07 13:10:44 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
    char    buffer[];
    int b_read;
    char    *line_frag;
    line_frag = NULL;
	while (/*distinto de salto de linea o EOF*/)
	{
        b_read = read(fd, buffer,)
		read(fd, buffer, n);
		if (b_read == 0)
			return (NULL);
		if (b_read == -1)
			return (NULL);
		while (read > 0)
		{
			get_next_line
		}
	}
}
