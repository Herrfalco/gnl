/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/20 17:08:58 by fcadet           ###   ########.fr       */
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
	char			buf[BUFFER_SIZE];
	ssize_t			buf_i;
	ssize_t			buf_sz;
	ssize_t			cat_sz;
}					t_file;

int					get_next_line(int fd, char **line);

#endif
