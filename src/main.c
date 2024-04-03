/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:51:13 by yde-goes          #+#    #+#             */
/*   Updated: 2024/04/03 20:08:17 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_data(t_push_swap *data, int argc, char **argv);

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
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (EXIT_SUCCESS);
}

static void	init_data(t_push_swap *data, int argc, char **argv)
{
	data->stack_a = fill_stack(argc, argv);
	data->stack_b = NULL;
	data->size_a = get_stack_size(data->stack_a);
	data->size_b = get_stack_size(data->stack_b);
	fill_index_stack(&data->stack_a);
}
