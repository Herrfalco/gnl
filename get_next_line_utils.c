/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:39:11 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/20 15:41:43 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	File function :
*/
void	init_file(t_file *file, int fd)
{
	file->fd = fd;
	file->buf_sz = BUFFER_SIZE;
	file->buf_i = file->buf_sz;
}

/*
**	String function :
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
**	Return function :
*/
int		out(t_out type, char **line, t_file *file)
{
	if (type == error)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (type == eol)
	{
		file->buf_i++;
		return (1);
	}
	if (type == eof)
	{
		free(*line);
		*line = NULL;
		file->fd = -1;
		return (0);
	}
	return (-1);
}
