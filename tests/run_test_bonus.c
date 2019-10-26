/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:34:34 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/26 11:44:20 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("tests/file", O_RDONLY);
	fd2 = open("tests/file2", O_RDONLY);
	while (get_next_line(fd1, &line1) > 0 && get_next_line(fd2, &line2) > 0)
	{
		printf("%s\n", line1);
		free(line1);
		printf("%s\n", line2);
		free(line2);
	}
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
}
