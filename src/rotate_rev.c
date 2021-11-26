/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:20 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/23 10:45:41 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rotate_a(t_ps *ps, int withlog)
{
	size_t	len;

	len = 0;
	while (len < ps->len)
		if (len++ < ps->len_a - 1)
			ft_swap(&ps->stack_a[len - 1], &ps->stack_a[len]);
	if (withlog)
		ps_putbuff(ps, "rra\n", 4);
}

void	rev_rotate_b(t_ps *ps, int withlog)
{
	size_t	len;

	len = 0;
	while (len < ps->len)
		if (len++ < ps->len_b - 1)
			ft_swap(&ps->stack_b[len - 1], &ps->stack_b[len]);
	if (withlog)
		ps_putbuff(ps, "rra\n", 4);
}

void	rev_rotate_ab(t_ps *ps)
{
	rev_rotate_a(ps, 0);
	rev_rotate_b(ps, 0);
	ps_putbuff(ps, "rrr\n", 4);
}
