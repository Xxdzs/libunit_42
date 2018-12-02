/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:43:17 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 17:43:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "ft_array.h"

typedef int				(*t_fptr)(void);

typedef struct s_test	t_test;

struct					s_test
{
	const char	*name;
	t_fptr		function;
};

# define NEW_TEST(NAME, FUNCTION) (t_test){NAME, FUNCTION}

int						load_test(t_array *list,
								const char *name,
								t_fptr function);
int						launch_tests(const char *name,
								t_array *list);

#endif
