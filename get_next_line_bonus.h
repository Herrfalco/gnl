/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/28 12:11:26 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD		1024

typedef enum		e_out
{
	eol,
	eof,
	error
}					t_out;

typedef struct		s_file
{
	int				used;
	char			buf[BUFFER_SIZE > 0 ? BUFFER_SIZE : 1];
	int				buf_i;
	int				buf_sz;
	int				cat_sz;
}					t_file;

void				init_file(t_file *files, int fd);
int					cat_buf(char **line, t_file *file);
int					out(t_out type, int fd, char **line, t_file *files);
int					get_next_line(int fd, char **line);

#endif
