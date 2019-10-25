/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:09:48 by fcadet            #+#    #+#             */
/*   Updated: 2019/10/25 22:15:49 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	put_str_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int		main(void)
{
	int		fd;

	fd = open("file2", O_CREAT | O_WRONLY);
	put_str_fd("\n", fd);
	put_str_fd("1\n", fd);
	put_str_fd("12\n", fd);
	put_str_fd("123\n", fd);
	put_str_fd("1234\n", fd);
	put_str_fd("12345\n", fd);
	put_str_fd("123456\n", fd);
	put_str_fd("1234567\n", fd);
	put_str_fd("12345678", fd);
	close(fd);
}
