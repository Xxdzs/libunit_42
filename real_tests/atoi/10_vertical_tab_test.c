/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_vertical_tab_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		vertical_tab_test(void)
{
	if (atoi("\v7057 CubanPrime") == ft_atoi("\v7057 CubanPrime"))
		return (0);
	else
		return (-1);
}
