/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:38:24 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/19 17:23:53 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	File functions
*/
int		init_file(t_file **file, int fd)
{
	if (*file)
		free(*file);
	if (!(*file = malloc(sizeof(t_file))))	
		return (0);
	(*file)->fd = fd;
	(*file)->buf_size = BUFFER_SIZE;
	(*file)->buf_i = (*file)->buf_size;
	return (1);
}

/*
**	String functions
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
	while (file->buf_i + len_b < file->buf_size
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
**	Return functions
*/
int		out(t_out type, char **line, t_file **file)
{
	if (type == error_f_line)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (type == error_f_line_file)
	{
		free(*file);
		*file = NULL;
		return (out(error_f_line, line, file));
	}
	if (type == eol)
	{
		(*file)->buf_i++;
		return (1);
	}
	if (type == eof)
	{
		out(error_f_line_file, line, file);
		return (0);
	}
	return (-1);
}

/*
**	Principal function
*/
int		get_next_line(int fd, char **line)
{
	static t_file		*file = NULL; 

	if (BUFFER_SIZE < 1 || fd < 0 || !line || !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (!file || fd != file->fd)
		if (!init_file(&file, fd))
			return (out(error_f_line, line, &file));
	while (file->buf_i >= file->buf_size || file->buf[file->buf_i] != '\n')
	{
		if (file->buf_i >= file->buf_size)
		{
			if ((file->buf_size = read(fd, file->buf, BUFFER_SIZE)) == -1)
				return (out(error_f_line_file, line, &file));
			if (!file->buf_size)
				return (**line ? out(eol, line, &file) : out(eof, line, &file));
			file->buf_i = 0;
		}
		if ((file->cat_size = cat_buf(line, file)) == -1)
			return (out(error_f_line_file, line, &file));
		file->buf_i += file->cat_size;
	}
	return (out(eol, line, &file));
}
