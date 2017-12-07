/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:00:08 by gschaetz          #+#    #+#             */
/*   Updated: 2016/12/12 11:36:06 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_test_tetri(char *str, int i)
{
	int l;

	l = 0;
	i++;
	while (i % 21 != 20)
	{
		if (str[i] == '\n')
			l++;
		i++;
	}
	if (l != 4)
		return (0);
	else
		return (i);
}

int	ft_tetri_test(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (i % 21 == 20 || i == 0)
		{
			i = ft_test_tetri(str, i);
		}
		if (i == 0)
			return (0);
	}
	return (1);
}

int	ft_verif_t(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '\n')
			i++;
		else if (str[i] == '#')
		{
			k++;
			i++;
		}
		else
			return (0);
	}
	if (k % 4 == 0)
		return (1);
	return (0);
}
