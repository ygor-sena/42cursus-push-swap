/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:03:59 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/16 15:27:32 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nbr_conv;
	int	signal;

	nbr_conv = 0;
	signal = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		nbr_conv = (nbr_conv * 10) + (*nptr - '0');
		nptr++;
	}
	return (signal * nbr_conv);
}
