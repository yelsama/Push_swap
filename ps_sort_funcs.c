/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:47:50 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/03 16:24:07 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	shortcut(t_ps_list **ska, t_ps_list **skb, int val)//, int pos)
// {
// 	rr_p12_p21(ska, skb, 1);
// 	// if ((*ska)->rank > val && pos > 2 && (*ska)->next != 0)
// 	// 	rr_p12_p21(ska, skb, 100);
// 	// else
// 	sk_rk_rrk(ska, skb, 102);
// }
static void	from_a2b(t_ps_list **stka, t_ps_list **stkb, int hr, int div)
{
	int	lim;
	int	chunk;

	chunk = hr / div;
	while (chunk <= hr)
	{
		lim = 0;
		while (lim + 1 < 2 * hr / div)
		{
			if ((*stka)->rank <= chunk)
			{
				rr_p12_p21(stka, stkb, 1);
				lim++;
			}
			else if ((*stka)->rank > chunk && (*stka)->rank <= chunk + hr / div)
			{
				rr_p12_p21(stka, stkb, 1);
				sk_rk_rrk(stka, stkb, 102);
				lim++;
			}
			else
				sk_rk_rrk(stka, stkb, 101);
		}
		chunk += 2 * (hr / div);
	}
}

static void	from_b2a(t_ps_list **stka, t_ps_list **stkb, int hr, int div)
{
	while (elmt_frm_head(stkb, hr) != 1)
	{
		if (elmt_frm_head(stkb, hr) > hr / div)
			sk_rk_rrk(stka, stkb, 12);
		else
			sk_rk_rrk(stka, stkb, 102);
	}
	rr_p12_p21(stka, stkb, 10);
	while (*stkb)
	{
		if ((*stka)->rank == ((*stkb)->rank + 1))
			rr_p12_p21(stka, stkb, 10);
		else if ((*stka)->rank == g_secnd(stkb) + 1)
		{
			sk_rk_rrk(stka, stkb, 1002);
			rr_p12_p21(stka, stkb, 10);
		}
		else if (elmt_frm_head(stkb, (*stka)->rank - 1) < (*stka)->rank / 2)
			sk_rk_rrk(stka, stkb, 102);
		else if (elmt_frm_head(stkb, (*stka)->rank - 1) >= (*stka)->rank / 2)
			sk_rk_rrk(stka, stkb, 12);
	}	
}

static void	sort_3(t_ps_list **stk)
{
	if ((*stk)->rank > g_secnd(stk))
		sk_rk_rrk(stk, stk, 1001);
	if ((*stk)->rank > g_last(stk))
		sk_rk_rrk(stk, stk, 11);
	if (g_secnd(stk) > g_last(stk))
	{
		sk_rk_rrk(stk, stk, 11);
		sk_rk_rrk(stk, stk, 1001);
	}
}

void	sort_50_less(t_ps_list **stka, t_ps_list **stkb, int hr)
{
	int	n;

	n = -1;
	if (hr < 4)
		sort_3(stka);
	else if (hr < 21)
	{
		while (hr - (++n) > 3)
		{
			while (elmt_frm_head(stka, n + 1) > (hr - n) / 2)
				sk_rk_rrk(stka, stkb, 11);
			while ((*stka)->rank != n + 1)
			{
				sk_rk_rrk(stka, stkb, 101);
			}
			rr_p12_p21(stka, stkb, 1);
		}
		sort_3(stka);
	}
	else
		sort_abv_50(stka, stkb, hr, 10);
	while (*stkb)
		rr_p12_p21(stka, stkb, 10);
}

void	sort_abv_50(t_ps_list **stka, t_ps_list **stkb, int hr, int div)
{
	from_a2b(stka, stkb, hr, div);
	while (*stka)
		rr_p12_p21(stka, stkb, 1);
	from_b2a(stka, stkb, hr, div);
}
