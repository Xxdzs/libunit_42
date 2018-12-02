/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strcmp_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strcmp_tests.h"

int		strcmp_launcher(void)
{
	t_array		test_list[1];

	test_list[0] = NEW_ARRAY(t_test);
	load_test(test_list, "pure alpha test", &pure_alpha_test);
	load_test(test_list, "empty s1 test", &empty_s1_test);
	load_test(test_list, "empty s2 test", &empty_s2_test);
	load_test(test_list, "empty both test", &empty_both_test);
	load_test(test_list, "null s1 test", &null_s1_test);
	load_test(test_list, "null s2 test", &null_s2_test);
	load_test(test_list, "null both test", &null_both_test);
	return (launch_tests("strcmp", test_list));
}
