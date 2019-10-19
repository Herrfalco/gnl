/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:46:31 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/19 19:22:06 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line_bonus.h"
//#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		fd2;
	char	*line;

	
	fd = open("tests/file", O_RDONLY);
	fd2 = open("tests/file2", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd2, &line);
	close(fd2);
	fd2 = open("tests/file2", O_RDONLY);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	return (0);
}
