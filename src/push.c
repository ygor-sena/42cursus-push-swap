/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:12:30 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/25 14:40:42 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dest);

void	push_a(t_push_swap **data, t_stack **stack_a, t_stack **stack_b)
{
	size_t	tmp_a;
	size_t	tmp_b;

	push(stack_b, stack_a);
	tmp_a = (*data)->size_a;
	tmp_b = (*data)->size_b;
	(*data)->size_a = tmp_a + 1;
	(*data)->size_b = tmp_b - 1;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_push_swap **data, t_stack **stack_a, t_stack **stack_b)
{
	size_t	tmp_a;
	size_t	tmp_b;

	push(stack_a, stack_b);
	tmp_a = (*data)->size_a;
	tmp_b = (*data)->size_b;
	(*data)->size_a = tmp_a - 1;
	(*data)->size_b = tmp_b + 1;
	ft_putstr_fd("pb\n", 1);
}

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}
