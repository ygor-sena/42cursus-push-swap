/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:49:25 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/19 18:34:55 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
