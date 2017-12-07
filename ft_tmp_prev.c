/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_prev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:52:10 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:54:43 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*ft_tmp_prev(t_fillit *tmp, t_fillit *save)
{
	if (save == tmp)
		save = tmp;
	else
	{
		while (save->next != tmp)
			save = save->next;
	}
	save->ok = 0;
	save->x = save->x + 1;
	return (save);
}
