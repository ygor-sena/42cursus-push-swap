/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:51:13 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/20 12:24:02 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->next != NULL)
	{
		ft_printf("%ld[%d] ", stack->nbr, index + 1);
		index++;
		stack = stack->next;
	}
	ft_printf("%ld[%d] \n", stack->nbr, index + 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = fill_stack(argc, argv);
	if (is_valid_arg(&stack_a))
		ft_printf("Let's sort it!\n");
	print_stack(stack_a);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	//push_a(&stack_a, &stack_b);
	swap_both(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
