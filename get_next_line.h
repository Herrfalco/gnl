/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/19 15:42:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_FD	4096

typedef enum		e_output
{
	eol,
	eof,
	error,
	error_f_line,
	error_f_line_file
}					t_output;

typedef struct		s_file
{
	int					fd;	
	char				buf[BUFFER_SIZE];
	ssize_t				buf_i;
	ssize_t				buf_size;
	ssize_t				cat_size;
}					t_file;

int					get_next_line(int fd, char **line);

#endif
