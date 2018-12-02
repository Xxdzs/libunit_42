/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:02 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 19:08:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wrong_atoi(const char *str)
{
	int		ans;
	int		sign;

	while (*str == ' ')
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	ans = 0;
	while (ft_isdigit(*str))
		ans = 10 * ans + *str++ - '0';
	return (sign * ans);
}
