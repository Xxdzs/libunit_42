/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_invalid_first_char_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		invalid_first_char_test(void)
{
	if (atoi("_197 Chen") == ft_atoi("_197 Chen"))
		return (0);
	else
		return (-1);
}
