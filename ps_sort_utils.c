/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:18:09 by ymohamed          #+#    #+#             */
/*   Updated: 2022/09/24 15:32:41 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_ps_list **stack)
{
	t_ps_list	*tmp;
	t_ps_list	*tmp1;

	if (!(*stack) || !((*stack)->next))
	{
		write(1, "Cant swap, No or only one elment\n", 34);
		return (1);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	tmp1 = (*stack)->next;
	tmp->next = tmp1;
	(*stack)->next = tmp;
	return (0);
}

int	push_stack(t_ps_list **dst, t_ps_list **src)
{
	t_ps_list	*tmp;
	t_ps_list	*tmp1;

	if (*(src) == 0 || (*src) == (*dst))
		return (1);
	tmp = malloc(sizeof(t_ps_list));
	if (!tmp)
		return (1);
	tmp->num = (*src)->num;
	tmp->rank = (*src)->rank;
	tmp->next = *dst;
	*dst = tmp;
	tmp1 = *src;
	*src = (*src)->next;
	free(tmp1);
	return (0);
}

int	rotate(t_ps_list **stack)
{
	t_ps_list	*new_end;
	t_ps_list	*old_end;

	if (!(*stack) || (*stack)->next == 0)
		return (1);
	new_end = *stack;
	*stack = (*stack)->next;
	old_end = *stack;
	while (old_end->next != 0)
		old_end = old_end->next;
	old_end->next = new_end;
	new_end->next = 0;
	return (0);
}

int	rev_rotate(t_ps_list **stack)
{
	t_ps_list	*new_start;
	t_ps_list	*to_find_last;

	if (!(*stack) || (*stack)->next == 0)
		return (1);
	new_start = *stack;
	while (new_start->next != 0)
	{
		to_find_last = new_start;
		new_start = new_start->next;
	}
	new_start->next = *stack;
	to_find_last->next = 0;
	*stack = new_start;
	return (0);
}
