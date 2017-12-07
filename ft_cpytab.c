/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:40:17 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:54:03 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mod_nul(int i)
{
	while (i % 5 != 0)
		i++;
	i--;
	return (i);
}

char	**ft_cpytab(char **tab, t_fillit *tmp, int x, int y)
{
	int k;
	int i;

	k = x;
	i = 0;
	while (tab[y] != NULL)
	{
		if (tab[y][x] == '\0')
			i = ft_mod_nul(i);
		if (tmp->content[i] == '\n' || tab[y][x] == '\0')
		{
			x = k;
			y++;
		}
		else
		{
			if (tmp->content[i] == tmp->alph)
				tab[y][x] = tmp->content[i];
			x++;
		}
		i++;
	}
	return (tab);
}
