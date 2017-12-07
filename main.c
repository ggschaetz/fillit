/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:28:13 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 12:59:42 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		write(1, "usage : ./fillit file\n", 22);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
			ft_lecture(fd);
		else
			write(1, "error\n", 6);
	}
	else if (argc > 2)
		write(1, "error\n", 6);
	return (0);
}
