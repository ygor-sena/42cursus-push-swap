/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:51:13 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/25 14:59:58 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	print_stack_a(t_stack *stack)
{
	int	index;

	if (!stack)
		return ;
	index = 0;
	ft_printf("A: ");
	while (stack->next != NULL)
	{
		ft_printf("%ld[%d] ", stack->nbr, stack->index);
		index++;
		stack = stack->next;
	}
	ft_printf("%ld[%d] \n", stack->nbr, stack->index);
}

void	print_stack_b(t_stack *stack)
{
	int	index;

	index = 0;
	if (!stack)
		return ;
	ft_printf("B: ");
	while (stack->next != NULL)
	{
		ft_printf("%ld[%d] ", stack->nbr, stack->index);
		index++;
		stack = stack->next;
	}
	ft_printf("%ld[%d] \n", stack->nbr, stack->index);
}
 */
static void	init_data(t_push_swap *data, int argc, char **argv)
{	
	data->stack_a = fill_stack(argc, argv);
	data->stack_b = NULL;
	data->size_a = get_stack_size(data->stack_a);
	data->size_b = get_stack_size(data->stack_b);
	fill_index_stack(&data->stack_a);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc == 1)
		return (EXIT_FAILURE);
	init_data(&data, argc, argv);
	if (is_valid_arg(&data.stack_a))
	{
		if (data.size_a <= 3)
			sort_three(&data.stack_a);
		else if (data.size_a <= 5)
			sort_five(&data);
		else
			sort_many(&data);
	}
	/* print_stack_a(data.stack_a);
	print_stack_b(data.stack_b); */
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (EXIT_SUCCESS);
}
