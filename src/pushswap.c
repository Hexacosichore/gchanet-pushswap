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
		ps->stack_a[cur_j] = i;
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
	while ((ps->max_num >> ps->max_bit) != 0)
		++ps->max_bit;
}

int	ps_init(int argc, char **argv, t_ps *ps)
{
	size_t	count;

	count = 0;
	ps->len = argc - 1;
	ps->len_a = ps->len;
	ps->len_b = 0;
	ps->op = 0;
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

int	ps_issorted(t_ps *ps)
{
	long long	tmp;
	int			i;

	if (ps->len_b != 0)
		return (0);
	i = ps->len_a - 1;
	tmp = ps->stack_a[i];
	while (--i > 0)
	{
		if (tmp < ps->stack_a[i])
			tmp = ps->stack_a[i];
		else
			return (0);
	}
	return (1);
}

// int	ps_containe_a(t_ps *ps, int c)
// {
// 	int	i;

// 	i = ps->len_a;
// 	while (i >= 0 && ps->len - (i + 1))
// 	{
// 		if (ps->stack_a[i] == c)
// 			return (1);
//		i--;
// 	}
// 	return (0);
// }

int	ps_containe_b(t_ps *ps, int c)
{
	int	i;

	i = ps->len_b;
	while (i >= 0 && ps->len - (i + 1))
	{
		if (ps->stack_b[i] == c)
			return (1);
		i--;
	}
	return (0);
}

int	ps_findindex_b(t_ps *ps, int c)
{
	int	i;

	i = ps->len_b - 1;
	while (i >= 0)
	{
		if (ps->stack_b[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int	ps_findindex_a(t_ps *ps, int c)
{
	int	i;

	i = ps->len_a - 1;
	while (i >= 0)
	{
		if (ps->stack_a[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int	ps_istop_b(t_ps *ps, int c)
{
	return (ps_findindex_b(ps, c) > (int)(ps->len_b / 2));
}


int	ps_resolve(t_ps *ps)
{
	long long		tmp_max;
	int				i;
	int				j;
	int				i_c;
	int				j_c;
	int				chunksize = 40;
	i = 1;
	j = 2;
	i_c = 0;
	j_c = 0;

	long long		tmpval;
	long long		proxval;
	long long		proxminval;
	long long		proxmaxval;


	while (ps->len_a > 0)
	{
		if(ps->stack_a[ps->len_a - 1] >= chunksize * (i - 1) && ps->stack_a[ps->len_a - 1] < chunksize * i)
		{
			push_b(ps);
			if (ps->len_b > 1 && ps->stack_b[ps->len_b - 1] < ps->stack_b[ps->len_b - 2])
				swap_b(ps);
			i_c++;
			if (i_c == chunksize)
			{
				i += 2;
				i_c = 0;
			}
		}
		else if(ps->stack_a[ps->len_a - 1] >= chunksize * (j - 1) && ps->stack_a[ps->len_a - 1] < chunksize * j)
		{
			push_b(ps);
			rotate_b(ps, 1);
			j_c++;
			if (j_c == chunksize)
			{
				j += 2;
				j_c = 0;
			}
		}
		else
		{	
			proxminval = ps->len_a;
			proxmaxval = 0;

			proxval = chunksize * (j - 1);
			while (proxval < chunksize * j)
			{
				tmpval = ps_findindex_a(ps, proxval);
				if (tmpval != -1 && tmpval < proxminval)
					proxminval = tmpval;
				if (tmpval != -1 && tmpval > proxmaxval)
					proxmaxval = tmpval;
				proxval++;
			}
			
			proxval = chunksize * (i - 1);
			while (proxval < chunksize * i)
			{
				tmpval = ps_findindex_a(ps, proxval);
				if (tmpval != -1 && tmpval < proxminval)
					proxminval = tmpval;
				if (tmpval != -1 && tmpval > proxmaxval)
					proxmaxval = tmpval;
				proxval++;
			}

			//printf("%lld %lld \n", proxminval, ps->len_a - proxmaxval);
			//rotate_a(ps, 1);
			if (proxminval >= ps->len_a - proxmaxval)
				rotate_a(ps, 1);
			else
				rev_rotate_a(ps, 1);
		}
		//if (ps->len_a > 1 && ps->len_b > 1
		//	&& ps->stack_a[ps->len_a - 1] < ps->stack_a[ps->len_a - 2] 
		//	&& ps->stack_b[ps->len_b - 1] < ps->stack_b[ps->len_b - 2])
		//	swap_ab(ps);
	}

	tmp_max = ps->len - 1;
	while (ps->len_b > 0)
	{
		while (1)
		{
			if (ps_istop_b(ps, tmp_max))
				rotate_b(ps, 1);
			else
				rev_rotate_b(ps, 1);
			if (ps->stack_b[ps->len_b - 1] == tmp_max)
			{
				push_a(ps);
				tmp_max--;
				break ;
			}
		}
	}
	
	return (0);
}

// int	ps_resolve(t_ps *ps)
// {
// 	long long		tmp_min;
// 	long long		i;
// 	long long		size_chunk;
// 	long long		curr_chunk;
// 	unsigned int	tmp_len_a;
// 	unsigned int	tmp_len_b;
// 	unsigned int	j;

// 	i = ps->len - 1;
// 	size_chunk = 20;
// 	curr_chunk = 1;
// 	while (i > 0)
// 	{
// 		if (ps->stack_a[i] <= size_chunk * curr_chunk)
// 			push_b(ps);
// 		else
// 	}




// 	return (0);
// 	while (tmp_max)
// 	{
// 		if (ps->stack_a[ps->len_a - 1] < ps->len / 3)
// 			push_b(ps);
// 		if (ps->stack_a[ps->len_a - 1] < (ps->len / 3) * 2)
// 		{
// 			push_b(ps);
// 			rotate_b(ps, 1);
// 		}
// 		else
// 			rotate_a(ps, 1);
// 		tmp_max--;
// 	}
// 	return (0);
// 	tmp_max = ps->len - 1;
// 	while (tmp_max - tmp_min != 1)
// 	{
// 		j = 0;
// 		while (j < tmp_len_a)
// 		{
// 			if (ps->stack_a[ps->len_a - 1] == tmp_min)
// 			{
// 				rotate_a(ps, 1);
// 				tmp_min++;
// 				// if (ps_containe_b(ps, tmp_min))
// 				// 	break ;
// 			}
// 			else
// 			{
// 				push_b(ps);
// 				// if (ps->len_b > 1 && ps->stack_b[ps->len_b - 1] == tmp_max)
// 				// {
// 				// 	rotate_b(ps, 1);
// 				// 	tmp_max--;
// 				// }
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		tmp_len_a = 0;
// 		tmp_len_b = ps->len_b - ((ps->len - 1) - tmp_max);
// 		while (j < tmp_len_b)
// 		{
// 			if (ps->stack_b[ps->len_b - 1] == tmp_min)
// 			{
// 				push_a(ps);
// 				rotate_a(ps, 1);
// 				tmp_min++;
// 			}
// 			else
// 			{
// 				push_a(ps);
// 				tmp_len_a++;
// 				// if (ps->len_a > 1 &&  ps->stack_a[ps->len_a - 1] == tmp_min)
// 				// {
// 				// 	rotate_a(ps, 1);
// 				// 	tmp_min++;
// 				// }
// 			}
// 			// if (ps->len_b > 0 && ps->stack_b[ps->len_b - 1] == tmp_max)
// 			// {
// 			// 	rotate_b(ps, 1);
// 			// 	tmp_max--;
// 			// 	j++;
// 			// }
// 			j++;
// 		}
// 	}
// 	return (0);
// }

// int	ps_resolve(t_ps *ps)
// {
// 	long long		tmp;
// 	unsigned int	i;
// 	unsigned int	j

// 	i = 0;
// 	while (!ps_issorted(ps) && i < ps->max_bit)
// 	{
// 		j = 0;
// 		while (j < ps->len)
// 		{
// 			tmp = ps->stack_a[ps->len_a - 1];
// 			if (((tmp >> i) & 1) == 1)
// 				rotate_a(ps, 1);
// 			else
// 				push_b(ps);
// 			j++;
// 		}
// 		while (ps->len_b != 0)
// 			push_a(ps);
// 		i++;
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (ps_init(argc, argv, &ps))
		ps_resolve(&ps);
	printf("OPP %d \n", ps.op);
	return (0);
}
