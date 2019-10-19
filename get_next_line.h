/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/20 00:06:58 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
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
	ssize_t			buf_i;
	ssize_t			buf_sz;
	ssize_t			cat_sz;
}					t_file;

int					get_next_line(int fd, char **line);

#endif
