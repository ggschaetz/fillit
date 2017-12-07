/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:28:08 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 14:03:55 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*ft_init_fm(char *str, char *str1)
{
	t_fillit	*tmp;
	int			j;
	char		tmp1[21];

	j = 0;
	while (j < 20)
	{
		if (str[j] == '#')
			tmp1[j] = 'A';
		else
			tmp1[j] = str[j];
		j++;
	}
	tmp1[j] = '\0';
	tmp = ft_lstnew(tmp1, 21);
	tmp = ft_decal(tmp, str1);
	tmp->alph = 'A';
	tmp->ok = 0;
	return (tmp);
}

char		*ft_creat_str1(int a)
{
	char	*str1;

	str1 = NULL;
	if (!(str1 = (char *)malloc(sizeof(char) * a + 1)))
		return (NULL);
	return (str1);
}

void		ft_init_tmp(t_fillit *tmp, int k)
{
	tmp->alph = 'A' + k;
	tmp->flag = k;
	tmp->ok = 0;
}

char		*ft_write(char *str, char *tmp1, int i, int k)
{
	int j;

	j = 0;
	while (j < 20)
	{
		if (str[i] == '#')
			tmp1[j] = 'B' + k;
		else
			tmp1[j] = str[i];
		i++;
		j++;
	}
	tmp1[j] = '\0';
	return (tmp1);
}

t_fillit	*ft_stock_trans(char *str, int i, int k)
{
	t_fillit	*tmp;
	t_fillit	*glp;
	t_fillit	*stmp;
	char		tmp1[21];

	tmp = ft_init_fm(str, ft_creat_str1(16));
	stmp = tmp;
	while (str[i])
	{
		ft_init_tmp(tmp, k);
		ft_write(str, tmp1, i, k);
		glp = ft_decal(ft_lstnew(tmp1, 21), ft_creat_str1(16));
		ft_lstadd(&glp, tmp);
		tmp = tmp->next;
		k++;
		i = i + 21;
	}
	ft_init_tmp(tmp, k);
	return (stmp);
}
