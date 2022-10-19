/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 04:49:25 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/19 04:50:53 by yde-goes         ###   ########.fr       */
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
