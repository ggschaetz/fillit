/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:31:29 by fmaury            #+#    #+#             */
/*   Updated: 2016/12/12 14:03:53 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 50046

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
	int				x;
	int				flag;
	int				ok;
	int				y;
	char			alph;
}					t_fillit;

int					ft_verif_liens(char *str, int j, int ret);
void				ft_lecture(int fd);
int					ft_valide(char *str);
t_fillit			*ft_stock_trans(char *str, int i, int k);
t_fillit			*ft_lstnew(char const *content, size_t content_size);
void				*ft_memcpy(char *dst, const char *src, size_t n);
t_fillit			*ft_decal(t_fillit *tmp, char *str1);
void				ft_assemblage(t_fillit *tmp, int carre);
void				ft_lstadd(t_fillit **alst, t_fillit *nouveau);
int					ft_verif_t(char *str);
int					ft_tetri_test(char *str);
t_fillit			*ft_tmp_prev(t_fillit *tmp, t_fillit *save);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
char				**ft_cpytab(char **tab, t_fillit *tmp, int x, int y);
int					ft_placement(char **tab, t_fillit *tmp, int x, int y);
void				ft_affich_tab(char **tab);
int					ft_isok(char **tab, t_fillit *tmp, int x, int y);

#endif
