/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 17:44:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf.h"
#include "ft_color.h"
#include <signal.h>

#define IS_CHILD 0

int				load_test(t_array *list, const char *name, t_fptr function)
{
	const t_test	test = NEW_TEST(name, function);

	fta_append(list, &test, 1);
	return (0);
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
			ft_printf("%sOK", COLOR(GREEN));
		else if (status == SIGBUS)
			ft_printf("%sBUSE", COLOR(BOLD, RED));
		else if (status == SIGSEGV)
			ft_printf("%sSIGV", COLOR(BOLD, RED));
		else
			ft_printf("%sKO", COLOR(RED));
		ft_printf("%s]", EOC);
	}
	return (status == 0);
}

int				launch_tests(const char *name, t_array *list)
{
	void		*iterator;
	unsigned	success;

	success = 0;
	iterator = ARRAY_ITERATOR(list);
	ft_printf("%s : ", name);
	while (ARRAY_HASNEXT(list, iterator))
		success += run_test((t_test*)iterator);
	ft_printf("\n%u / %u tests passed\n", success, list->size);
	return (-(success != list->size));
}
