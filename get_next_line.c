/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:38:24 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/25 22:07:57 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_file		f = { -1, { 0 }, 0, 0, 0 };

	if (BUFFER_SIZE < 1 || fd < 0 || !line || !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (f.fd != fd)
		init_file(&f, fd);
	while (f.buf_i >= f.buf_sz || f.buf[f.buf_i] != '\n')
	{
		if (f.buf_i >= f.buf_sz)
		{
			if ((f.buf_sz = read(fd, f.buf, BUFFER_SIZE)) == -1)
				return (out(error, line, &f));
			if (!f.buf_sz)
				return (out(eof, line, &f));
			f.buf_i = 0;
		}
		if ((f.cat_sz = cat_buf(line, &f)) == -1)
			return (out(error, line, &f));
		f.buf_i += f.cat_sz;
	}
	return (out(eol, line, &f));
}
