/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assemblage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:13:20 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:56:58 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_retab(int carre, char **tab, int i)
{
	int		j;

	if (!(tab = (char **)malloc(sizeof(char*) * (carre + 1))))
		return (NULL);
	while (i < carre)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (carre + 1))))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < carre)
	{
		j = 0;
		while (j < carre)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		ft_reset_tmp(t_fillit *tmp)
{
	while (tmp != NULL)
	{
		tmp->x = 0;
		tmp->y = 0;
		tmp->ok = 0;
		tmp = tmp->next;
	}
}

t_fillit	*ft_backtrack(t_fillit *tmp)
{
	t_fillit *save;

	save = tmp;
	while (tmp->ok == 1)
		tmp = tmp->next;
	return (ft_tmp_prev(tmp, save));
}

void		ft_assemblage(t_fillit *tmp, int carre)
{
	t_fillit	*save;
	char		**tab;
	int			q;

	save = tmp;
	tab = ft_retab(carre, NULL, 0);
	while (ft_placement(tab, tmp, tmp->x, tmp->y) != 0)
	{
		q = ft_placement(tab, tmp, tmp->x, tmp->y);
		if (q == 1)
			tmp = ft_backtrack(save);
		else if (q == -1)
		{
			carre++;
			ft_reset_tmp(save);
		}
		tab = ft_retab(carre, tab, 0);
		tmp = save;
		while (tmp->ok == 1)
		{
			tab = ft_cpytab(tab, tmp, tmp->x, tmp->y);
			tmp = tmp->next;
		}
	}
}
