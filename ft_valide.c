/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:29:18 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:18:04 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif(int *tab, int n)
{
	if ((tab[0] == 12 * n) && (tab[1] == 4 * n) &&\
		(tab[2] == (5 * n) - 1) && tab[3] == 0)
		return (1);
	else
		return (0);
}

int		ft_while(char *str, int *tab, int flag, int n)
{
	while (str[tab[4]] != '\0')
	{
		if (str[tab[4]] == '.')
		{
			tab[0]++;
			flag = 1;
		}
		else if (str[tab[4]] == '#')
			tab[1]++;
		else if (str[tab[4]] == '\n')
			tab[2]++;
		else
			tab[3]++;
		if (tab[0] % 12 == 0 && flag == 1)
		{
			n++;
			flag = 0;
		}
		tab[4]++;
	}
	return (ft_verif(tab, n));
}

int		ft_valide(char *str)
{
	int tab[5];
	int flag;
	int	n;

	n = 0;
	flag = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	return (ft_while(str, tab, flag, n));
}
