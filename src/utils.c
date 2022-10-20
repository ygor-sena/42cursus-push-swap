/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:49:25 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/20 12:34:57 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_stack(char *input_nbr, t_stack **stack_a);

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

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		param;
	int		index;
	char	**input_nbr;

	param = 1;
	stack_a = NULL;
	while (param < argc)
	{
		input_nbr = ft_split(argv[param], SPACE_CHR);
		index = 0;
		while (input_nbr[index])
		{
			if (parse_stack(input_nbr[index], &stack_a))
			{
				free_split(input_nbr);
				exit_program(&stack_a, NULL);
			}
			index++;
		}
		free_split(input_nbr);
		param++;
	}
	return (stack_a);
}

static int	parse_stack(char *input_nbr, t_stack **stack_a)
{
	long long	cast_nbr;
	t_stack		*new_node;

	cast_nbr = ft_atol(input_nbr);
	if (is_nondigit(input_nbr) \
		|| cast_nbr > MAX_INT || cast_nbr < MIN_INT)
	{
		ft_printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	new_node = create_new_nbr(cast_nbr);
	if (!new_node)
		return (EXIT_FAILURE);
	if (!stack_a)
		*stack_a = new_node;
	else
		add_back_nbr(stack_a, new_node);
	return (EXIT_SUCCESS);
}
