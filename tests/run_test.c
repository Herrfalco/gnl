/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:46:31 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/19 16:52:55 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include "get_next_line_bonus.h"
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;

	
	fd = open("tests/file", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	get_next_line(fd, &line);
	close(fd);
	fd = open("tests/file2", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
