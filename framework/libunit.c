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
#include <signal.h>

#define IS_CHILD 0

int				load_test(t_array *list, const char *name, t_fptr function)
{
	fta_push_back(list, NEW_TEST(name, function));
}

static unsigned	run_test(t_test *test)
{
	int		status;

	if (fork() == IS_CHILD)
		exit(test->function());
	else
	{
		wait(&status);
		ft_printf("[%s ", test->name);
		if (status == 0)
			ft_printf("OK");
		else if (status == SIGBUS)
			ft_printf("BUSE");
		else if (status == SIGSEGV)
			ft_printf("SIGV");
		else
			ft_printf("KO");
		ft_printf("]");
	}
	return (status == 0);
}

int				launch_tests(const char *name, t_array *list)
{
	void		*iterator = ARRAY_ITERATOR(list);
	unsigned	success = 0;

	ft_printf("%s : ", name);
	while (ARRAY_HASNEXT(iterator))
		success += run_test((t_test*)iterator);	
	ft_printf("\n%u / %u tests passed\n", success, fta_size(list));
	return (-(success != fta_size(list)));
}
