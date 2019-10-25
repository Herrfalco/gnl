/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:53:56 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/21 09:14:47 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD		256

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
	int				buf_i;
	int				buf_sz;
	int				cat_sz;
}					t_file;

int					get_next_line(int fd, char **line);

#endif
