/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:03:59 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/17 17:05:18 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	long long	nbr_conv;
	int			signal;

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
