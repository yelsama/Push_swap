/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:27:30 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/03 22:45:23 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_ps_list **stk)
{
	int			n;
	t_ps_list	*tmp;

	if (!stk || (*stk)->next == 0)
		return (1);
	n = 0;
	tmp = *stk;
	while (tmp->next != 0)
	{
		if (tmp->rank != ++n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static char	*parsing(int c, char **v, int *flag)
{
	int		i;
	char	*fulinput;

	i = 0;
	fulinput = v[1];
	while (++i < c - 1)
		fulinput = ps_strjoin(fulinput, v[i + 1], flag);
	if (!fulinput)
		*flag = 1;
	if (*flag)
	{
		free(fulinput);
		return (0);
	}
	return (fulinput);
}

static int	sort(t_ps_list **stka, int high_rank)
{
	t_ps_list	*stkb;

	stkb = 0;
	if (is_sorted(stka))
		return (0);
	if (high_rank < 51)
		sort_50_less(stka, &stkb, high_rank);
	else if (high_rank < 251)
		sort_abv_50(stka, &stkb, high_rank, 10);
	else
		sort_abv_50(stka, &stkb, high_rank, 18);
	if (stkb)
		ps_lstclear(&stkb);
	return (0);
}

int	main(int c, char **v)
{
	int			flag;
	char		*fulinput;
	ssize_t		*ranked_nums;
	int			num_count;
	t_ps_list	*stka;

	flag = 0;
	if (c < 2)
		return (0);
	fulinput = parsing(c, v, &flag);
	if (flag)
		return (0);
	num_count = 0;
	ranked_nums = set_rank_find_dup(fulinput, &num_count, &flag);
	if (flag)
		write(2, "Error\n", 6);
	if (!flag)
		stka = fill_stack(fulinput, ranked_nums, num_count, &flag);
	if (!flag)
		sort(&stka, num_count);
	if (c > 2)
		free(fulinput);
	heap_free(flag, ranked_nums, &stka);
	return (0);
}
