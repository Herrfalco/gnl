/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:34:33 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/26 11:27:01 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static t_file		f[MAX_FD] = {{ 0, { 0 }, 0, 0, 0 }};

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= MAX_FD || !line
		|| !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (!f[fd].used)
		init_file(f, fd);
	while (f[fd].buf_i >= f[fd].buf_sz || f[fd].buf[f[fd].buf_i] != '\n')
	{
		if (f[fd].buf_i >= f[fd].buf_sz)
		{
			if ((f[fd].buf_sz = read(fd, f[fd].buf, BUFFER_SIZE)) == -1)
				return (out(error, fd, line, f));
			if (!f[fd].buf_sz)
				return (out(eof, fd, line, f));
			f[fd].buf_i = 0;
		}
		if ((f[fd].cat_sz = cat_buf(line, &f[fd])) == -1)
			return (out(error, fd, line, f));
		f[fd].buf_i += f[fd].cat_sz;
	}
	return (out(eol, fd, line, f));
}
