/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:54:23 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/25 14:45:06 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_duplicate_nbr(t_stack *stack_a);
static int		parse_stack(char *input_nbr, t_stack **stack_a);

t_bool	is_valid_arg(t_stack **stack_a)
{
	if (is_duplicate_nbr(*stack_a))
	{
		ft_printf(ERROR_MSG);
		return (FALSE);
	}
	if (is_ordered_stack(*stack_a))
		return (FALSE);
	return (TRUE);
}

t_bool	is_nondigit(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (!ft_isdigit(string[index]) \
			&& string[index] != SPACE_CHR \
			&& string[index] != '-')
			return (TRUE);
		index++;
	}
	return (FALSE);
}

static t_bool	is_duplicate_nbr(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a->next != NULL)
	{
		tmp = stack_a->next;
		while (tmp != NULL)
		{
			if (stack_a->nbr == tmp->nbr)
				return (TRUE);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (FALSE);
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
