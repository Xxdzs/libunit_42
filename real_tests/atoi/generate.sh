# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 22:42:13 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 17:09:20 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

header="atoi_tests.h"
launcher="00_atoi_launcher.c"
ft_header="\
/* ************************************************************************** */\n\
/*                                                                            */\n\
/*                                                        :::      ::::::::   */\n\
/*   libunit.c                                          :+:      :+:    :+:   */\n\
/*                                                    +:+ +:+         +:+     */\n\
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */\n\
/*                                                +#+#+#+#+#+   +#+           */\n\
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */\n\
/*   Updated: 2018/12/01 21:39:06 by angagnie         ###   ########.fr       */\n\
/*                                                                            */\n\
/* ************************************************************************** */\n"

echo "Generating atoi tests"

# Header
echo "$ft_header" > $header
echo "#ifndef $(echo $header | tr '[a-z].' '[A-Z]_')" >> $header
echo "# define $(echo $header | tr '[a-z].' '[A-Z]_')\n" >> $header

# Launcher
echo "$ft_header" > $launcher
echo '#include "libunit.h"' >> $launcher
echo "#include \"$header\"\n" >> $launcher
echo "int\t\tatoi_launcher(void)\n{" >> $launcher
echo "\tt_array\ttest_list[1];" >> $launcher
echo "\n\ttest_list[0] = NEW_ARRAY(t_test);" >> $launcher

count=1
for input in "basic_number|28" "negative|-8128" "empty|" "negative_zero|-0" \
	"space| 496" "plus_sign|+1729 Ramanujan" "tab| \\\t 33550336 Perfect" \
	"carriage_return| \\\r +877 Bell Prime" "form_feed| \\\f 16127 Carol Prime" \
	"vertical_tab| \\\v 7057 Cuban Prime" "two_plus_signs|++3" \
	"invalid_first_char|_197 Chen" "leading_zeros| 000231" \
	"combo|\\\r\\\v\\\n-00000987654321" "int_min|-2147483648" "int_max|2147483647"
do
	name=${input%%|*}_test
	str='"'${input#*|}'"'
	filename=$(printf "%.2i" $count)_${name}.c
	echo $filename
	echo "$ft_header" > $filename
	echo '#include "libft.h"' >> $filename
	echo '#include <stdlib.h>\n' >> $filename
	echo "int\t\t${name}(void)\n{" >> $filename
	echo "\tif (atoi(${str}) == ft_atoi(${str}))" >> $filename
	echo "\t\treturn (0);" >> $filename
	echo "\telse" >> $filename
	echo "\t\treturn (-1);\n}" >> $filename
	echo "int\t\t${name}(void);" >> $header
	echo "\tload_test(test_list, \"$(echo $name | tr '_' ' ')\", &$name);" >> $launcher
	let count++
done

echo "\treturn (launch_tests(\"atoi\", test_list));\n}" >> $launcher
echo "\n#endif" >> $header
echo "Done"
