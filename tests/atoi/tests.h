/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:52:19 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 19:05:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

int		tests_launcher(void);

int		ok_test(void);
int		ko_test(void);
int		buse_test(void);
int		sigv_test(void);

int		wrong_atoi(const char *str);

#endif
