/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:35:03 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/25 22:35:34 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		init_file(t_file *file, int fd)
{
	file->fd = fd;
	file->buf_sz = BUFFER_SIZE;
	file->buf_i = file->buf_sz;
}

int			cat_buf(char **line, t_file *file)
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

int			out(t_out type, char **line, t_file *file)
{
	if (type == error)
	{
		free(*line);
		return (-1);
	}
	if (type == eol)
	{
		file->buf_i++;
		return (1);
	}
	if (type == eof)
	{
		file->fd = -1;
		return (0);
	}
	return (-1);
}
