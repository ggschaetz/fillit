/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:55:05 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:58:22 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_return_col(t_fillit *tmp, int col, int ligne)
{
	if ((tmp->content[ligne * 5 + col + 3] >= 'A' && tmp->content[ligne\
		* 5 + col + 3] <= 'Z') && (tmp->content[ligne * 5 + col + 2] < 'A' ||\
		tmp->content[ligne * 5 + col + 2] > 'Z'))
		col = col - 2;
	else if ((tmp->content[ligne * 5 + col + 4] >= 'A' && tmp->content[ligne\
			* 5 + col + 4] <= 'Z') || (tmp->content[ligne * 5 + col + 9] >= 'A'\
			&& tmp->content[ligne * 5 + col + 9] <= 'Z'))
		col--;
	return (col);
}

t_fillit	*ft_return_tmp(t_fillit *tmp, int col, int k, char *str1)
{
	int tab[2];

	tab[0] = 0;
	tab[1] = 0;
	while (str1[tab[0]])
	{
		k = col;
		tab[1] = tab[1] + col;
		while (str1[tab[1]] != '\n')
		{
			tmp->content[tab[0]] = str1[tab[1]];
			tab[0]++;
			tab[1]++;
		}
		while (k != 0)
		{
			tmp->content[tab[0]] = '.';
			k--;
			tab[0]++;
		}
		tmp->content[tab[0]] = '\n';
		tab[1]++;
		tab[0]++;
	}
	return (tmp);
}

char		*ft_str(t_fillit *tmp, int ligne, int k, char *str1)
{
	int i;

	i = 0;
	while (tmp->content[ligne * 5 + i])
	{
		str1[i] = tmp->content[ligne * 5 + i];
		i++;
	}
	while (i < 20)
	{
		if (k % 5 == 0)
			str1[i] = '\n';
		else
			str1[i] = '.';
		i++;
		k++;
	}
	str1[i] = '\0';
	return (str1);
}

t_fillit	*ft_decal(t_fillit *tmp, char *str1)
{
	int		ligne;
	int		col;

	ligne = 0;
	col = 0;
	while ((tmp->content[ligne * 5 + col] < 'A' || tmp->content[ligne\
			* 5 + col] > 'Z') && tmp->content[ligne * 5 + col] != '\0')
	{
		if (tmp->content[ligne * 5 + col] == '\n')
		{
			ligne++;
			col = 0;
		}
		else
			col++;
	}
	col = ft_return_col(tmp, col, ligne);
	str1 = ft_str(tmp, ligne, 1, str1);
	tmp = ft_return_tmp(tmp, col, 0, str1);
	free(str1);
	return (tmp);
}
