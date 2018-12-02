/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:02 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 21:35:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wrong_atoi(char *str)
{
	int		ans;
	int		sign;

	sign = 1;
	while (*str == ' ')
		++str;
	if (*str == '-')
	{
		sign = -1;
		*str = '+';
	}
	if (*str == '+')
		++str;
	ans = 0;
	while (ft_isdigit(*str))
		ans = 10 * ans + *str++ - '0';
	return (sign * ans);
}
