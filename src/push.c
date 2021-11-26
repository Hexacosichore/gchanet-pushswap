/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:41:18 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/23 10:19:38 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_ps *ps)
{
	ps->stack_a[ps->len_a++] = ps->stack_b[--ps->len_b];
	ps_putbuff(ps, "pa\n", 3);
}

void	push_b(t_ps *ps)
{
	ps->stack_b[ps->len_b++] = ps->stack_a[--ps->len_a];
	ps_putbuff(ps, "pb\n", 3);
}
