/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_itoa_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "itoa_tests.h"

int		itoa_launcher(void)
{
	t_array		test_list[1];

	test_list[0] = NEW_ARRAY(t_test);
	load_test(test_list, "basic 1 test", &basic_1_test);
	load_test(test_list, "basic 2 test", &basic_2_test);
	load_test(test_list, "min test", &min_test);
	load_test(test_list, "max test", &max_test);
	load_test(test_list, "zero test", &zero_test);
	return (launch_test(test_list));
}
