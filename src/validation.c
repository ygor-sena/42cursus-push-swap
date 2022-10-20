/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:54:23 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/20 12:32:33 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_ordered_stack(t_stack *stack_a);
static t_bool	is_duplicate_nbr(t_stack *stack_a);

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
