/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_min_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		min_test(void)
{
	if (strcmp(ft_itoa(-2147483648), "-2147483648") == 0)
		return (0);
	else
		return (-1);
}
