/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:51:13 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/20 10:22:45 by ygorgsena        ###   ########.fr       */
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

	//stack_a = NULL;
	//stack_b = NULL;
	stack_a = ft_calloc(1, sizeof(*stack_a));
	stack_b = ft_calloc(1, sizeof(*stack_b));
	/* stack_a = malloc(1 * sizeof(*stack_a));
	stack_b = malloc(1 * sizeof(*stack_b)); */
	if (is_valid_arg(argc, argv, &stack_a))
		ft_printf("Let's sort it!\n");
	print_stack(stack_a);
	print_stack(stack_b);
	push_b(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	stack_cleaning(&stack_a);
	stack_cleaning(&stack_b);
	return (EXIT_SUCCESS);
}
