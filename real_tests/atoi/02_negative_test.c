/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_negative_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		negative_test(void)
{
	if (atoi("-8128") == ft_atoi("-8128"))
		return (0);
	else
		return (-1);
}
