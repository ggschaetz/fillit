/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_liens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:43:06 by gschaetz          #+#    #+#             */
/*   Updated: 2016/12/12 11:49:21 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_choice(char **tab)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (j + 1 < 4 && tab[i][j] == '#' && tab[i][j + 1] == '#')
				nb++;
			if (j - 1 >= 0 && tab[i][j] == '#' && tab[i][j - 1] == '#')
				nb++;
			if (i + 1 < 4 && tab[i][j] == '#' && tab[i + 1][j] == '#')
				nb++;
			if (i - 1 >= 0 && tab[i][j] == '#' && tab[i - 1][j] == '#')
				nb++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nb);
}

char		**ft_cpy_tab(char *dest, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i != 4)
	{
		while (j <= 4)
		{
			if (dest[k] == '\n')
				tab[i][j] = '\0';
			else
				tab[i][j] = dest[k];
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_conv_in_tab(char *dest)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		i++;
	}
	return (ft_cpy_tab(dest, tab));
}

char		*ft_split_str(char *str, int j)
{
	int		i;
	char	*dest;

	i = 1;
	if (!(dest = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	while (i % 20 != 0)
	{
		dest[i - 1] = str[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_verif_liens(char *str, int j, int ret)
{
	char	*dest;
	char	**tab;
	int		res;

	while (j <= ret)
	{
		dest = ft_split_str(str, j);
		tab = ft_conv_in_tab(dest);
		free(dest);
		j++;
		if ((ft_choice(tab) != 6 && ft_choice(tab) != 8))
		{
			res = 0;
			j = j + ret;
		}
		else
			res = 1;
		j = j + 20;
		free(tab);
	}
	return (res);
}
