/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:49:25 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/25 14:44:28 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp_stack;

	if (!stack)
		return ;
	tmp_stack = *stack;
	while (tmp_stack != NULL)
	{
		tmp_stack = tmp_stack->next;
		free(*stack);
		*stack = tmp_stack;
	}
	*stack = NULL;
}

void	exit_program(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	exit (EXIT_FAILURE);
}
