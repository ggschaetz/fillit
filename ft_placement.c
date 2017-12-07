/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:55:14 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:53:37 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tmp_ok(t_fillit *tmp, int x, int y)
{
	tmp->x = x;
	tmp->y = y;
	tmp->ok = 1;
}

int		ft_placement(char **tab, t_fillit *tmp, int x, int y)
{
	if (tmp != NULL)
	{
		if (tmp->ok == 1)
			return (ft_placement(tab, tmp->next, 0, 0));
		if (ft_isok(tab, tmp, x, y) == -1)
			return (ft_placement(tab, tmp, ++x, y));
		if (ft_isok(tab, tmp, x, y) == 1)
			return (ft_placement(tab, tmp, 0, ++y));
		if (ft_isok(tab, tmp, x, y) == 0)
		{
			ft_tmp_ok(tmp, x, y);
			return (ft_placement(ft_cpytab(tab, tmp, x, y), tmp->next, 0, 0));
		}
		if (ft_isok(tab, tmp, x, y) == -2)
		{
			tmp->ok = 0;
			return (1);
		}
		if (ft_isok(tab, tmp, x, y) == 2)
			return (-1);
	}
	ft_affich_tab(tab);
	return (0);
}
