/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:51:13 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/19 04:53:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->next != NULL)
	{
		ft_printf("Index %d: %ld\n", index + 1, stack->nbr);
		index++;
		stack = stack->next;
	}
	ft_printf("Index %d: %ld\n", index + 1, stack->nbr);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	//t_stack  stack_b;
	stack_a = ft_calloc(1, sizeof(*stack_a));
	if (is_valid_arg(argc, argv, stack_a))
		ft_printf("Let's sort it!\n");
	/* NOTE: Temporary function */
	print_stack(stack_a);
	stack_cleaning(&stack_a);
	return (EXIT_SUCCESS);
}
