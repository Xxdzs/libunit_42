/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_tests_launcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:10:00 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 20:45:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int		tests_launcher(void)
{
	t_tests		tests;

	tests = NEW_TESTS;
	load_test(&tests, "OK test", &ok_test);
	load_test(&tests, "K0 test", &ko_test);
	load_test(&tests, "SIGV test", &sigv_test);
	load_test(&tests, "BUSE test", &buse_test);
	return (launch_tests("Tests", &tests));
}
