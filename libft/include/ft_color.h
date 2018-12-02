/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:47:45 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 14:59:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "libft.h"

# define NORMAL 0
# define BOLD 1
# define DARK 2
# define ITALIC 3
# define UNDERLINED 4

# define RED	31
# define GREEN	32
# define YELLOW	33
# define BLUE	34
# define PURPLE	35
# define CYAN	36
# define WHITE	37

# define COLOR(...) CAT(_COLOR_,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
# define _COLOR_1(A) TO_STR(\e[CAT(A,m))
# define _COLOR_2(A,B) TO_STR(\e[A;CAT(B,m))
# define _COLOR_3(A,B,C) TO_STR(\e[A;B;CAT(C,m))
# define _COLOR_4(A,B,C,D) TO_STR(\e[A;B;C;CAT(D,m))
# define _COLOR_5(A,B,C,D,E) TO_STR(\e[A;B;C;D;CAT(E,m))

# define EOC	"\033[0m"

#endif
