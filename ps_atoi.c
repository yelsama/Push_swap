/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:31:11 by ymohamed          #+#    #+#             */
/*   Updated: 2022/09/19 15:55:17 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calcu(ssize_t *nb, ssize_t *md, int *i, char *ptr);

ssize_t	ps_atoi(const char *str, int *i)
{
	char		*ptr;
	ssize_t		sn;
	ssize_t		nb;
	ssize_t		md;

	ptr = (char *)str;
	sn = 1;
	nb = 0;
	md = 0;
	while (ptr[*i] == ' ' || (ptr[*i] > 8 && ptr[*i] < 14))
		(*i)++;
	if (ptr[*i] == '-' || ptr[*i] == '+')
		if (ptr[(*i)++] == '-')
			sn = sn * -1;
	if (ptr[*i] < '0' || ptr[*i] > '9')
		return (2147483649 * sn);
	while (ptr[*i] == '0')
		(*i)++;
	calcu(&nb, &md, i, ptr);
	if (md > 10)
		return (2147483649 * sn);
	return (nb * sn);
}

static void	calcu(ssize_t *nb, ssize_t *md, int *i, char *ptr)
{
	while (ptr[*i] >= '0' && ptr[*i] <= '9' && *md < 11)
	{
		*nb = *nb * 10 + (ptr[*i] - 48);
		(*md)++;
		(*i)++;
	}
	if (!(ptr[*i] == '\0' || ptr[*i] == ' '))
		*md = 11;
}
