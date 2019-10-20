/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/20 22:01:12 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef enum		e_out
{
	eol,
	eof,
	error
}					t_out;

typedef struct		s_file
{
	int				fd;
	char			buf[BUFFER_SIZE];
	int				buf_i;
	int				buf_sz;
	int				cat_sz;
}					t_file;

int					get_next_line(int fd, char **line);
void				init_file(t_file *file, int fd);
int					cat_buf(char **line, t_file *file);
int					out(t_out type, char **line, t_file *file);

#endif
