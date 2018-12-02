/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int		atoi_launcher(void)
{
	t_array	test_list[1];

	test_list[0] = NEW_ARRAY(t_test);
	load_test(test_list, "basic test", &basic_test);
	load_test(test_list, "negative test", &negative_test);
	load_test(test_list, "empty test", &empty_test);
	load_test(test_list, "negative zero test", &negative_zero_test);
	load_test(test_list, "space test", &space_test);
	load_test(test_list, "plus sign test", &plus_sign_test);
	load_test(test_list, "tab test", &tab_test);
	load_test(test_list, "carriage return test", &carriage_return_test);
	load_test(test_list, "form feed test", &form_feed_test);
	load_test(test_list, "vertical tab test", &vertical_tab_test);
	load_test(test_list, "two plus signs test", &two_plus_signs_test);
	load_test(test_list, "invalid first char test", &invalid_first_char_test);
	load_test(test_list, "leading zeros test", &leading_zeros_test);
	load_test(test_list, "combo test", &combo_test);
	load_test(test_list, "int min test", &int_min_test);
	load_test(test_list, "int max test", &int_max_test);
	return (launch_test(test_list));
}
