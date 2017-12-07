/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:26:19 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 12:59:04 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_size_carre(char *str)
{
	int i;
	int k;
	int size;

	i = 0;
	size = 2;
	k = 0;
	while (str[i] != '\0')
	{
		while (i % 21 != 20)
			i++;
		k++;
		i++;
	}
	if (k * 4 > size * size)
		size++;
	return (size);
}

void		ft_call(char *buf, int ret)
{
	if (buf[0] == '\0')
		return ;
	buf[ret] = '\0';
	if (ft_valide(buf) == 1 && ft_verif_liens(buf, 0, ret) == 1 && \
	ft_verif_t(buf) == 1 && ft_tetri_test(buf) == 1)
		ft_assemblage(ft_stock_trans(buf, 21, 0), ft_size_carre(buf));
	else
		write(1, "error\n", 6);
}

void		ft_lecture(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	buf[0] = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		i = 1;
		if (ret < 0 || ((ret + 1) % 21 != 0))
		{
			write(1, "error\n", 6);
			return ;
		}
		else
			ft_call(buf, ret);
	}
	if (i == 0)
		write(1, "error\n", 6);
}
