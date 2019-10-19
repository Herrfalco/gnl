/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:38:24 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/19 23:58:42 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
**	File functions :
*/
void	init_file(t_file *file, int fd)
{
	file->fd = fd;
	file->buf_sz = BUFFER_SIZE;
	file->buf_i = file->buf_sz;
}

/*
**	String functions :
*/
ssize_t		cat_buf(char **line, t_file *file)
{
	ssize_t	len_a;
	ssize_t	len_b;
	ssize_t	i;
	ssize_t	j;
	char	*new;

	len_a = 0;
	while ((*line)[len_a])
		len_a++;	
	len_b = 0;
	while (file->buf_i + len_b < file->buf_sz
		&& file->buf[file->buf_i + len_b] != '\n')
		len_b++;
	if (!(new = malloc((len_a + len_b + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (++i < len_a)
		new[i] = (*line)[i];
	free(*line);
	j = -1;
	while (++j < len_b)
		new[i + j] = file->buf[file->buf_i + j];		
	new[i + j] = '\0';
	*line = new;
	return (len_b);
}

/*
**	Return functions :
*/
int		out(t_out type, int fd, char **line, t_file *file)
{
	if (type == error)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (type == eol)
	{
		file.buf_i++;
		return (1);
	}
	if (type == eof)
	{
		free(*line);
		*line = NULL;
		file.fd = -1;
		return (0);
	}
	return (-1);
}

/*
**	Principal function :
*/
int		get_next_line(int fd, char **line)
{
	static t_file		f;

	if (BUFFER_SIZE < 1 || fd < 0 || !line || !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (f.fd == -1)
		init_file(&f, fd);
	while (f.buf_i >= f.buf_sz || f.buf[f.buf_i] != '\n')
	{
		if (f.buf_i >= f.buf_sz)
		{
			if ((f.buf_sz = read(fd, f.buf, BUFFER_SIZE)) == -1)
				return (out(error, fd, line, &f));
			if (!f.buf_sz)
				return (**line ? 1 : out(eof, fd, line, &f));
			f.buf_i = 0;
		}
		if ((f.cat_sz = cat_buf(line, &f)) == -1)
			return (out(error, fd, line, &f));
		f.buf_i += f.cat_sz;
	}
	return (out(eol, fd, line, &f));
}
