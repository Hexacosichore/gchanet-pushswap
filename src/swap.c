/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:27:03 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/23 10:27:03 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_ps *ps)
{
	ft_swap(&ps->stack_a[ps->len_a - 1], &ps->stack_a[ps->len_a - 2]);
	ps_putbuff(ps, "sa\n", 3);
}

void	swap_b(t_ps *ps)
{
	ft_swap(&ps->stack_b[ps->len_b - 1], &ps->stack_b[ps->len_b - 2]);
	ps_putbuff(ps, "sb\n", 3);
}

void	swap_ab(t_ps *ps)
{
	ft_swap(&ps->stack_a[ps->len_a - 1], &ps->stack_a[ps->len_a - 2]);
	ft_swap(&ps->stack_b[ps->len_b - 1], &ps->stack_b[ps->len_b - 2]);
	ps_putbuff(ps, "ss\n", 3);
}
