/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:34:33 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/25 22:39:13 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	init_file(t_file *files, int fd)
{
	files[fd].used = 1;
	files[fd].buf_sz = BUFFER_SIZE;
	files[fd].buf_i = files[fd].buf_sz;
}

int		cat_buf(char **line, t_file *file)
{
	int		len_a;
	int		len_b;
	int		i;
	int		j;
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

int		out(t_out type, int fd, char **line, t_file *files)
{
	if (type == error)
	{
		free(*line);
		return (-1);
	}
	if (type == eol)
	{
		files[fd].buf_i++;
		return (1);
	}
	if (type == eof)
	{
		files[fd].used = 0;
		return (0);
	}
	return (-1);
}

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
