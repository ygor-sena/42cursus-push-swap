/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:53:44 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/19 04:54:10 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(long long nbr)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*get_last_nbr(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	add_back_nbr(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = get_last_nbr(*lst);
	temp->next = new;
}

void	stack_cleaning(t_stack **lst)
{
	t_stack	*temp_lst;

	if (!lst)
		return ;
	temp_lst = *lst;
	while (temp_lst != NULL)
	{
		temp_lst = temp_lst->next;
		free(*lst);
		*lst = temp_lst;
	}
	*lst = NULL;
}

int	stack_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
