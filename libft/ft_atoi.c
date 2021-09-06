/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:48:06 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/01 17:57:30 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			is_n;
	long int	rest;

	i = 0;
	is_n = 1;
	rest = 0;
	if (str[0] == '0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_n *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		rest = (rest * 10) + (str[i] - '0');
		i++;
	}
	return (rest * is_n);
}
