/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:15:53 by ymohamed          #+#    #+#             */
/*   Updated: 2022/09/24 23:09:53 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ft_lstlast(t_ps_list *lst)
{
	t_ps_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

static void	ft_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*temp;

	temp = NULL;
	if (*lst == 0)
	{
		*lst = new;
		(*lst)->next = 0;
	}
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

static t_ps_list	*ps_lstnew(ssize_t content, int *flag, int r)
{
	t_ps_list		*n;

	n = malloc(sizeof(t_ps_list));
	if (!n)
	{
		*flag = 1;
		return (NULL);
	}
	n->rank = r;
	n->num = (int)content;
	n->next = 0;
	return (n);
}

t_ps_list	*fill_stack(char *fulinput, ssize_t *rank_nums, int nc, int *flag)
{
	int			i;
	int			n;
	ssize_t		num;
	t_ps_list	*stack;
	t_ps_list	*node;

	i = -1;
	stack = NULL;
	while (fulinput[++i] != 0)
	{
		num = ps_atoi(fulinput, &i);
		n = 0;
		while (n < nc && num != rank_nums[n])
			n++;	
		node = ps_lstnew(num, flag, ++n);
		ft_lstadd_back(&stack, node);
		if (fulinput[i] == '\0')
			break ;
	}
	if (*flag)
		ps_lstclear(&stack);
	return (stack);
}

void	ps_lstclear(t_ps_list **lst)
{
	if (!lst)
		return ;
	if ((*lst)->next != 0)
		ps_lstclear(&(*lst)->next);
	free(*lst);
	*lst = 0;
}
