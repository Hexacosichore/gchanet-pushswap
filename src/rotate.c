/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:20 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/23 10:46:16 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_ps *ps, int withlog)
{
	size_t	len;

	len = ps->len;
	while (len)
		if (len-- < ps->len_a)
			ft_swap(&ps->stack_a[len + 1], &ps->stack_a[len]);
	if (withlog)
		ps_putbuff(ps, "ra\n", 3);
}

void	rotate_b(t_ps *ps, int withlog)
{
	size_t	len;

	len = ps->len;
	while (len)
		if (len-- < ps->len_b)
			ft_swap(&ps->stack_b[len + 1], &ps->stack_b[len]);
	if (withlog)
		ps_putbuff(ps, "rb\n", 3);
}

void	rotate_ab(t_ps *ps)
{
	rotate_a(ps, 0);
	rotate_b(ps, 0);
	ps_putbuff(ps, "rr\n", 3);
}
