/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 19:41:00 by angagnie         ###   ########.fr       */
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
		ft_printf("\t%s :\t[", test->name);
		if (status == 0)
			ft_printf("%sOK", COLOR(BOLD, GREEN));
		else if (status == SIGBUS)
			ft_printf("%sBUSE", COLOR(BOLD, RED));
		else if (status == SIGSEGV)
			ft_printf("%sSIGV", COLOR(BOLD, RED));
		else
			ft_printf("%sKO", COLOR(RED));
		ft_printf("%s]\n", EOC);
	}
	return (status == 0);
}

int				launch_tests(const char *name, t_array *list)
{
	void		*iterator;
	unsigned	success;

	success = 0;
	iterator = ARRAY_ITERATOR(list);
	ft_printf("%s {\n", name);
	while (ARRAY_HASNEXT(list, iterator))
		success += run_test((t_test*)iterator);
	ft_printf("\t%s%u / %u %stests passed%s\n}\n\n",
			  (success == list->size ? COLOR(GREEN) : COLOR(RED)),
			  success, list->size,
			  COLOR(ITALIC, DARK, WHITE), EOC);
	return (-(success != list->size));
}
