/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pushswap.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gchanet <gchanet@student.42lyon.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/11/16 13:51:58 by gchanet		   #+#	#+#			 */
/*   Updated: 2021/11/23 08:53:00 by gchanet		  ###   ########lyon.fr   */
/*																			*/
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

void	ps_simplify_get_min(t_ps *ps)
{
	long long		cur_min;
	unsigned int	cur_j;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < ps->len)
	{
		cur_min = INT_MAX;
		j = 0;
		while (j < ps->len)
		{
			if (ps->stack_a[j] == -1 && ps->tmp[j] < cur_min)
			{
				cur_min = ps->tmp[j];
				cur_j = j;
			}
			j++;
		}
		ps->stack_a[cur_j] = ft_itob(i);
		i++;
	}
	ps->max_num = ps->stack_a[cur_j];
}

void	ps_simplify(t_ps *ps)
{
	unsigned int	i;

	i = 0;
	while (i < ps->len)
		ps->stack_a[i++] = -1;
	ps_simplify_get_min(ps);
}

int	ps_init(int argc, char **argv, t_ps *ps)
{
	size_t	count;

	count = 0;
	ps->len = argc - 1;
	ps->len_a = ps->len;
	ps->len_b = 0;
	ps->max_bit = 0;
	ps->stack_a = (long long *)malloc(sizeof(long long) * ps->len);
	ps->stack_b = (long long *)malloc(sizeof(long long) * ps->len);
	ps->tmp = (long long *)malloc(sizeof(long long) * ps->len);
	if (!ps->stack_a || !ps->stack_b)
		return (0);
	while (--argc)
		ps->tmp[count++] = ft_atoi(argv[argc]);
	ps_simplify(ps);
	return (1);
}

#include <stdio.h>

int	ps_resolve(t_ps *ps)
{
	long long		tmp;
	unsigned int	i;
	unsigned int	j;

	while ((ps->max_num >> ps->max_bit) != 0)
		++ps->max_bit;
	i = 0;
	while (i < ps->max_bit)
	{
		j = 0;
		while (j < ps->len)
		{
			tmp = ps->stack_a[ps->len_a - 1];
			if (((tmp >> i) & 1) == 1)
				rotate_a(ps, 1);
			else
				push_b(ps);
			j++;
		}
		while (ps->len_b != 0)
			push_a(ps);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (ps_init(argc, argv, &ps))
		ps_resolve(&ps);
	ft_putchar('\n');
	return (0);
}
