/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:24:51 by ymohamed          #+#    #+#             */
/*   Updated: 2022/10/03 22:46:19 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		c;

	ptr = (char *)s;
	c = 0;
	while (ptr[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ps_strjoin(char *s1, char *s2, int *flag)
{
	char		*fs;
	int			l;
	int			i;
	static int	f;

	l = ft_strlen(s1);
	fs = malloc(sizeof(char) * (l + ft_strlen(s2) + 2));
	if (!fs)
	{
		*flag = f;
		return (NULL);
	}
	i = -1;
	while (++i < l)
		fs[i] = s1[i];
	fs[i++] = ' ';
	l = 0;
	while (s2[l] != '\0')
		fs[i++] = s2[l++];
	fs[i] = s2[l];
	if (f)
		free(s1);
	f++;
	return (fs);
}

static int	count_strings(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	is_douplicate_setord(ssize_t *num, int n)
{
	int		i;
	ssize_t	temp;

	i = -1;
	if (num[n] > INT_MAX || num[n] < INT_MIN)
		return (1);
	while (++i < n)
	{
		if (num[i] == num[n])
			return (1);
	}
	i = -1;
	while (++i < n)
	{
		if (num[i] > num[n])
		{
			temp = num[i];
			num[i] = num[n];
			num[n] = temp;
		}
	}
	return (0);
}

ssize_t	*set_rank_find_dup(char *fulinput, int *count, int *flag)
{
	ssize_t	*nums;
	int		i;
	int		n;

	nums = 0;
	*count = count_strings(fulinput, ' ');
	if (*count)
		nums = malloc(sizeof(ssize_t) * (*count));
	if (!nums)
		*flag = 1;
	i = -1;
	n = 0;
	while (fulinput[++i] != 0 && (!(*flag)) && n < *count)
	{
		nums[n] = ps_atoi(fulinput, &i);
		*flag = is_douplicate_setord(nums, n);
		n++;
		if (fulinput[i] == '\0')
			break ;
	}
	if (*flag && nums)
		free (nums);
	return (nums);
}
