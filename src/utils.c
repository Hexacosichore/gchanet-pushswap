/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:27:03 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/25 21:50:04 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_putbuff(t_ps *ps, char *str, char len)
{
	(void) ps;
	(void) len;
	ft_putstr(str);
}

void	ps_free(t_ps *ps)
{
	if (!ps)
		return ;
	if (ps->stack_a)
		free(ps->stack_a);
	if (ps->stack_b)
		free(ps->stack_b);
}

void	ft_swap(long long *a, long long *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ps_debug(t_ps *ps)
{
	size_t	len;

	len = ps->len;
	while (len)
	{
		if (len <= ps->len_a)
			ft_putnbr(ps->stack_a[len - 1]);
		ft_putchar('\t');
		if (len <= ps->len_b)
			ft_putnbr(ps->stack_b[len - 1]);
		ft_putchar('\n');
		len--;
	}
	ft_putchar('\n');
}

long long	ft_itob(int n)
{
	long long	bin;
	int			rem;
	int			i;

	bin = 0;
	i = 1;
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	return (bin);
}
