/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_tab_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		tab_test(void)
{
	if (atoi(" \t33550336 Perfect") == ft_atoi(" \t33550336 Perfect"))
		return (0);
	else
		return (-1);
}
