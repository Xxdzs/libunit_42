# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 22:42:13 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 21:07:34 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_header="\
/* ************************************************************************** */\n\
/*                                                                            */\n\
/*                                                        :::      ::::::::   */\n\
/*   &           :+:      :+:    :+:   */\n\
/*                                                    +:+ +:+         +:+     */\n\
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */\n\
/*                                                +#+#+#+#+#+   +#+           */\n\
/*   Created: $(date +'%Y/%m/%d %H:%M:%S') by angagnie          #+#    #+#             */\n\
/*   Updated: $(date +'%Y/%m/%d %H:%M:%S') by angagnie         ###   ########.fr       */\n\
/*                                                                            */\n\
/* ************************************************************************** */\n"

generate()
{
	fun=$1
	shift
	lib=$1
	shift
	header="${fun}_tests.h"
	launcher="00_${fun}_launcher.c"

	echo "Generating ${fun} tests"
	mkdir -p $fun
	cd $fun

	# Header
	echo "$ft_header" | sed "s/&/$(printf %-40s $header)/" > $header
	echo "#ifndef $(echo $header | tr '[a-z].' '[A-Z]_')" >> $header
	echo "# define $(echo $header | tr '[a-z].' '[A-Z]_')\n" >> $header

	# Launcher
	echo "$ft_header" | sed "s/&/$(printf %-40s $launcher)/" > $launcher
	echo '#include "libunit.h"' >> $launcher
	echo "#include \"$header\"\n" >> $launcher
	echo "int\t\t${fun}_launcher(void)\n{" >> $launcher
	echo "\tt_tests\t\ttest_list[1];" >> $launcher
	echo "\n\ttest_list[0] = NEW_TESTS;" >> $launcher

	count=1
	for input in $@
	do
		name=${input%%|*}_test
		str='"'${input#*|}'"'
		filename=$(printf "%.2i" $count)_${name}.c
		echo "\t$filename"
		echo "$ft_header" | sed "s/&/$(printf %-40s $filename)/" > $filename
		echo '#include "libft.h"' >> $filename
		echo "#include <$lib.h>\n" >> $filename
		echo "int\t\t${name}(void)\n{" >> $filename
		echo "\tif (${fun}(${str}) == ft_${fun}(${str}))" >> $filename
		echo "\t\treturn (0);" >> $filename
		echo "\telse" >> $filename
		echo "\t\treturn (-1);\n}" >> $filename
		echo "int\t\t${name}(void);" >> $header
		echo "\tload_test(test_list, \"$(echo $name | tr '_' ' ')\", &$name);" >> $launcher
		let count++
	done

	echo "\treturn (launch_tests(\"${fun}\", test_list));\n}" >> $launcher
	echo "\n#endif" >> $header
	cd ..
}

if test $# = 0
then
	generate "strlen" "string" 'basic_string|Hello\040World' \
		'empty_string|' 'other|\011!@#$%^&*()'
	generate "atoi" "stdlib" "basic_number|28" "negative|-8128" "empty|" "negative_zero|-0" \
		"space|\040-496" "plus_sign|+1729Ramanujan" "tab|\\\t33550336Perfect" \
		"carriage_return|\\\r+877BellPrime" "form_feed|\\\f16127CarolPrime" \
		"vertical_tab|\\\v7057CubanPrime" "two_plus_signs|++3" \
		"invalid_first_char|_197Chen" "leading_zeros|000231" \
		"combo|\040\\\r\\\v\\\n\040-00000987654321" "int_min|-2147483648" "int_max|2147483647"
else
	if test $1 = "fclean"
	then
		rm -rf strlen atoi
	fi
fi