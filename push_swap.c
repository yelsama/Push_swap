/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:27:30 by ymohamed          #+#    #+#             */
/*   Updated: 2022/09/24 16:46:41 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort(t_ps_list **stack_a)
{
	t_ps_list	*stack_a_copy;
	// t_ps_list	*stack_b;

	rotate(stack_a);
	rotate(stack_a);
	stack_a_copy = *stack_a;
	while (stack_a_copy->next != NULL)
	{
		printf("rank %d\n", stack_a_copy->rank);
		printf("%d\n", stack_a_copy->num);
		stack_a_copy = stack_a_copy->next;
	}	
	printf("rank %d\n", stack_a_copy->rank);
	printf("%d\n", stack_a_copy->num);
}

static void	heap_free(int flag, ssize_t *ranked_nums, t_ps_list **stack_a)
{
	if (!flag)
	{
		free(ranked_nums);
		ps_lstclear(stack_a);
	}
}

int	main(int c, char **v)
{
	int			flag;
	char		*fulinput;
	ssize_t		*ranked_nums;
	int			num_count;
	t_ps_list	*stack_a;

	flag = 0;
	if (c < 2)
		return (0);
	fulinput = parsing(c, v, &flag);
	if (flag)
		return (0);
	num_count = 0;
	ranked_nums = set_rank_find_dup(fulinput, &num_count, &flag);
	if (flag)
		write(1, "Error\n", 7);
	if (!flag)
		stack_a = fill_stack(fulinput, ranked_nums, num_count, &flag);
	if (!flag)
		sort(&stack_a);
	if (c > 2)
		free(fulinput);
	heap_free(flag, ranked_nums, &stack_a);
	return (0);
}
