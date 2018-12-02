/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_empty_both_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		empty_both_test(void)
{
	char	*s1;
	char	*s2;

	s1 = "";
	s2 = "";
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		return (0);
	else
		return (-1);
}
