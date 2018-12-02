/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:41:10 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 20:41:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

int		strlen_launcher(void)
{
	t_tests		test_list[1];

	test_list[0] = NEW_TESTS;
	load_test(test_list, "basic string test", &basic_string_test);
	load_test(test_list, "empty string test", &empty_string_test);
	load_test(test_list, "other test", &other_test);
	return (launch_tests("strlen", test_list));
}
