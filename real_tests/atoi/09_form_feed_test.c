/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_form_feed_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		form_feed_test(void)
{
	if (atoi("\f -16127 CarolPrime") == ft_atoi("\f -16127 CarolPrime"))
		return (0);
	else
		return (-1);
}
