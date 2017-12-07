/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:18:22 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 13:59:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*ft_lstnew(char const *content, size_t content_size)
{
	t_fillit	*new;

	if (!(new = (t_fillit *)malloc(sizeof(t_fillit) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (char*)malloc(sizeof(char) * content_size)))
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
