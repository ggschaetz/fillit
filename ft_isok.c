/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:57:43 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:52:57 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_return(t_fillit *tmp, int nbd, char **tab, int y)
{
	if (nbd == 4)
		return (0);
	if (tmp->alph == 'A' && tab[y] == NULL)
		return (2);
	return (-2);
}

int		ft_modok_nul(int i)
{
	while (i % 5 != 0)
		i++;
	i--;
	return (i);
}

int		ft_escroc(t_fillit *tmp, int i, int nbd)
{
	if (tmp->content[i] == tmp->alph)
		nbd++;
	return (nbd);
}

int		*ft_tabi(int *tabi, int x)
{
	tabi[0] = 0;
	tabi[1] = 0;
	tabi[2] = x;
	return (tabi);
}

int		ft_isok(char **tab, t_fillit *tmp, int x, int y)
{
	int tabi[3];

	ft_tabi(tabi, x);
	while (tmp->content[tabi[0]] && tab[y] != NULL)
	{
		tabi[1] = ft_escroc(tmp, tabi[0], tabi[1]);
		if (tab[y][x] >= 'A' && tab[y][x] <= 'Z' &&
			tmp->content[tabi[0]] == tmp->alph)
			return (-1);
		else if (tab[y][x] == '\0')
		{
			if (tmp->content[tabi[0]] == tmp->alph)
				return (1);
			tabi[0] = ft_modok_nul(tabi[0]);
		}
		if (tmp->content[tabi[0]] == '\n' || tab[y][x] == '\0')
		{
			x = tabi[2];
			y++;
		}
		else
			x++;
		tabi[0]++;
	}
	return (ft_return(tmp, tabi[1], tab, y));
}
