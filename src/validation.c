/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:54:23 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/19 04:59:23 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_ordered_stack(t_stack *stack_a);
static t_bool	is_duplicate_nbr(t_stack *stack_a);
static int		fill_stack(int argc, char **argv, t_stack *stack_a);
static int		parse_stack(char *input_nbr, t_stack *stack_a);

t_bool	is_valid_arg(int argc, char **argv, t_stack *stack_a)
{
	if (argc == 1 || fill_stack(argc, argv, stack_a))
		return (FALSE);
	if (is_duplicate_nbr(stack_a))
	{
		ft_printf(ERROR_MSG);
		return (FALSE);
	}
	if (is_ordered_stack(stack_a))
		return (FALSE);
	return (TRUE);
}

static t_bool	is_ordered_stack(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (FALSE);
		stack_a = stack_a->next;
	}
	return (TRUE);
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

static int	fill_stack(int argc, char **argv, t_stack *stack_a)
{
	int		param;
	int		index;
	char	**input_nbr;

	param = 1;
	while (param < argc)
	{
		input_nbr = ft_split(argv[param], SPACE_CHR);
		index = 0;
		while (input_nbr[index])
		{
			if (parse_stack(input_nbr[index], stack_a))
			{
				free_split(input_nbr);
				return (EXIT_FAILURE);
			}
			index++;
		}
		free_split(input_nbr);
		param++;
	}
	return (EXIT_SUCCESS);
}

static int	parse_stack(char *input_nbr, t_stack *stack_a)
{
	long long	converted;
	t_stack		*new_node;

	converted = ft_atol(input_nbr);
	if (is_nondigit(input_nbr) \
		|| converted > MAX_INT || converted < MIN_INT)
	{
		ft_printf(ERROR_MSG);
		return (EXIT_FAILURE);
	}
	if (!stack_a->nbr)
		stack_a->nbr = ft_atol(input_nbr);
	else
	{
		new_node = create_node(converted);
		if (!new_node)
			return (EXIT_FAILURE);
		add_back_nbr(&stack_a, new_node);
	}
	return (EXIT_SUCCESS);
}
