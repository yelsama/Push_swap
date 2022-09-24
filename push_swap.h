/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:36:13 by ymohamed          #+#    #+#             */
/*   Updated: 2022/09/24 15:29:36 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct push_swap_list
{
	int						rank;
	int						num;
	struct push_swap_list	*next;
}	t_ps_list;
ssize_t		ps_atoi(const char *str, int *i);
char		*ps_strjoin(char *s1, char *s2, int *flag);
t_ps_list	*fill_stack(char *fulinput, ssize_t *rank_nums, int nc, int *flag);
ssize_t		*set_rank_find_dup(char *fulinput, int *count, int *flag);
void		ps_lstclear(t_ps_list **lst);
int			swap_stack(t_ps_list **stack);
int			push_stack(t_ps_list **dst, t_ps_list **src);
int			rotate(t_ps_list **stack);
int			rev_rotate(t_ps_list **stack);

#endif