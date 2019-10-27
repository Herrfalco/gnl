/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:46:31 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/27 14:49:48 by herrfalco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
