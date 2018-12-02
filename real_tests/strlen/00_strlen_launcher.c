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
#include "strlen_tests.h"

int		strlen_launcher(void)
{
	t_array		test_list[1];

	test_list[0] = NEW_ARRAY(t_test);
	load_test(test_list, "basic test", &basic_test);
	load_test(test_list, "empty string test", &empty_string_test);
	load_test(test_list, "other test", &other_test);
	load_test(test_list, "null test", &null_test);
	return (launch_tests("strlen", test_list));
}
