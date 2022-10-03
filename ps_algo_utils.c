/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:30:45 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/03 01:59:03 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_last(t_ps_list **stack)
{
	t_ps_list	*elnt;

	if (!*stack || (*stack)->next == 0)
		return (0);
	elnt = ft_lstlast(*stack);
	return (elnt->rank);
}

int	g_secnd(t_ps_list **stack)
{
	t_ps_list	*elnt;

	if (!*stack || (*stack)->next == 0)
		return (0);
	elnt = *stack;
	elnt = elnt->next;
	return (elnt->rank);
}

int	elmt_frm_head(t_ps_list **stack, int elmt_r)
{
	t_ps_list	*wrk_stk;
	int			cnt;

	cnt = 1;
	wrk_stk = *stack;
	while (wrk_stk)
	{
		if (wrk_stk->rank != elmt_r)
			cnt++;
		else
			break ;
		wrk_stk = wrk_stk->next;
	}
	return (cnt);
}

void	sk_rk_rrk(t_ps_list **stka, t_ps_list **stkb, int id)
{
	if (id == 11)
		if (rev_rotate(stka))
			write(1, "rra\n", 4);
	if (id == 12)
		if (rev_rotate(stkb))
			write(1, "rrb\n", 4);
	if (id == 101)
		if (rotate(stka))
			write(1, "ra\n", 3);
	if (id == 102)
		if (rotate(stkb))
			write(1, "rb\n", 3);
	if (id == 1001)
		if (swap_stack(stka))
			write(1, "sa\n", 3);
	if (id == 1002)
		if (swap_stack(stkb))
			write(1, "sb\n", 3);
}

void	rr_p12_p21(t_ps_list **stka, t_ps_list **stkb, int id)
{
	if (id == 1)
		if (push_stack(stkb, stka))
			write(1, "pb\n", 3);
	if (id == 10)
		if (push_stack(stka, stkb))
			write(1, "pa\n", 3);
	if (id == 100)
		if (rotate(stka) && rotate(stkb))
			write(1, "rr\n", 3);
}
