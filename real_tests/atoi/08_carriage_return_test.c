/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_carriage_return_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:55:49 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 21:55:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		carriage_return_test(void)
{
	if (atoi("\r+877BellPrime") == ft_atoi("\r+877BellPrime"))
		return (0);
	else
		return (-1);
}
