# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 22:42:13 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 13:44:47 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

header="atoi_tests.h"
launcher="00_launcher.c"

echo "Generating atoi tests"

# Header
echo "#ifndef $(echo $header | tr '[a-z].' '[A-Z]_')" > $header
echo "# define $(echo $header | tr '[a-z].' '[A-Z]_')\n" >> $header

# Launcher
echo '#include "libunit.h"' > $launcher
echo "#include \"$header\"\n" >> $launcher
echo "int\t\tatoi_launcher(void)\n{" >> $launcher
echo "\tt_array\ttest_list[1];" >> $launcher
echo "\n\ttest_list[0] = NEW_ARRAY(t_test);" >> $launcher

count=1
for input in "basic|28" "negative|-8128" "empty|" "negative_zero|-0" "space| 496" "plus_sign|+1729 Ramanujan" "tab| \\\t 33550336 Perfect" \
	"carriage_return| \\\r +877 Bell Prime" "form_feed| \\\f 16127 Carol Prime" "vertical_tab| \\\v 7057 Cuban Prime" "two_plus_signs|++3" \
	"invalid_first_char|_197 Chen" "leading_zeros| 000000000002311 Euclid Prime" "combo|\\\r \\\v \\\n -0000000987654321" \
	"int_min|-2147483648" "int_max|2147483647"
do
	name=${input%%|*}_test
	str='"'${input#*|}'"'
	filename=$(printf "%.2i" $count)_${name}.c
	echo $filename "\t\t$str"
	echo '#include "libft.h"' > $filename
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

echo "\treturn (launch_test(test_list));\n}" >> $launcher
echo "\n#endif" >> $header
echo "Done"
