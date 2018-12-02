/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_TESTS_H
# define ATOI_TESTS_H

int		basic_number_test(void);
int		negative_test(void);
int		empty_test(void);
int		negative_zero_test(void);
int		space_test(void);
int		plus_sign_test(void);
int		tab_test(void);
int		carriage_return_test(void);
int		form_feed_test(void);
int		vertical_tab_test(void);
int		two_plus_signs_test(void);
int		invalid_first_char_test(void);
int		leading_zeros_test(void);
int		combo_test(void);
int		int_min_test(void);
int		int_max_test(void);

#endif
