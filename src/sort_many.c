/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:14:46 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/25 15:32:27 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_bit(int index, int position_bit);
static void	push_all_a(t_push_swap *data);

void	sort_many(t_push_swap *data)
{
	size_t	index_a;
	size_t	size_a;
	size_t	digit_pos;

	digit_pos = 0;
	size_a = get_stack_size(data->stack_a);
	while (!is_ordered_stack(data->stack_a))
	{
		index_a = 0;
		while (index_a < size_a && !is_ordered_stack(data->stack_a))
		{
			if (check_bit(data->stack_a->index, digit_pos))
				rotate_a(&data->stack_a);
			else
				push_b(&data, &data->stack_a, &data->stack_b);
			index_a++;
		}
		push_all_a(data);
		digit_pos++;
	}
}

static int	check_bit(int index, int position_bit)
{
	int	mask;

	mask = 1 << (position_bit);
	if (index & mask)
		return (1);
	return (0);
}

static void	push_all_a(t_push_swap *data)
{
	while (data->size_b)
	{
		data->size_b = get_stack_size(data->stack_b);
		push_a(&data, &data->stack_a, &data->stack_b);
	}
}
