/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:36 by gchanet           #+#    #+#             */
/*   Updated: 2021/11/25 20:04:07 by gchanet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_ps
{
	long long		*stack_a;
	long long		*stack_b;
	long long		*tmp;
	long long		max_num;
	long long		max_bit;
	unsigned int	len_a;
	unsigned int	len_b;
	unsigned int	len;
}			t_ps;

void			ft_swap(long long *a, long long *b);
void			ps_debug(t_ps *ps);
void			ps_putbuff(t_ps *ps, char *str, char len);
void			ps_free(t_ps *ps);
long long		ft_itob(int n);

void			push_a(t_ps *ps);
void			push_b(t_ps *ps);
void			swap_a(t_ps *ps);
void			swap_b(t_ps *ps);
void			swap_ab(t_ps *ps);
void			rotate_a(t_ps *lst, int withlog);
void			rotate_b(t_ps *lst, int withlog);
void			rotate_ab(t_ps *ps);
void			rev_rotate_a(t_ps *lst, int withlog);
void			rev_rotate_b(t_ps *lst, int withlog);
void			rev_rotate_ab(t_ps *ps);

#endif
