/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:16:04 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/25 14:45:27 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_four(t_push_swap *data);
static void	operate_stack(void (*operation)(t_stack **),
				t_push_swap *data, size_t steps);

void	sort_five(t_push_swap *data)
{
	size_t	smallest_a;
	t_stack	*penul;
	t_stack	*last;

	if (data->size_a == 4)
		sort_four(data);
	else
	{
		smallest_a = get_smallest_index(&data->stack_a);
		penul = get_penul_nbr(data->stack_a);
		last = get_last_nbr(data->stack_a);
		if (smallest_a == data->stack_a->next->index)
			swap_a(&data->stack_a);
		else if (smallest_a == data->stack_a->next->next->index)
			operate_stack(rotate_a, data, 2);
		else if (smallest_a == penul->index)
			operate_stack(reverse_a, data, 2);
		else if (smallest_a == last->index)
			reverse_a(&data->stack_a);
		push_b(&data, &data->stack_a, &data->stack_b);
		if (!is_ordered_stack(data->stack_a))
			sort_four(data);
		push_a(&data, &data->stack_a, &data->stack_b);
	}
}

static void	sort_four(t_push_swap *data)
{
	size_t	smallest_a;
	t_stack	*penul;
	t_stack	*last;

	smallest_a = get_smallest_index(&data->stack_a);
	penul = get_penul_nbr(data->stack_a);
	last = get_last_nbr(data->stack_a);
	if (smallest_a == data->stack_a->next->index)
		swap_a(&data->stack_a);
	else if (smallest_a == penul->index)
		operate_stack(rotate_a, data, 2);
	else if (smallest_a == last->index)
		reverse_a(&data->stack_a);
	push_b(&data, &data->stack_a, &data->stack_b);
	if (!is_ordered_stack(data->stack_a))
		sort_three(&data->stack_a);
	push_a(&data, &data->stack_a, &data->stack_b);
}

static void	operate_stack(void (*operation)(t_stack **),
							t_push_swap *data, size_t steps)
{
	while (steps--)
		operation(&data->stack_a);
}
