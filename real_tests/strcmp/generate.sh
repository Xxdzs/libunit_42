# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 22:42:13 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 22:47:42 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

function="strcmp"
header="${function}_tests.h"
launcher="00_${function}_launcher.c"
ft_header="\
/* ************************************************************************** */\n\
/*                                                                            */\n\
/*                                                        :::      ::::::::   */\n\
/*   &                     :+:      :+:    :+:   */\n\
/*                                                    +:+ +:+         +:+     */\n\
/*   By: weilin <marvin@42.fr>                      +#+  +:+       +#+        */\n\
/*                                                +#+#+#+#+#+   +#+           */\n\
/*   Created: 2018/12/01 21:39:01 by angagnie          #+#    #+#             */\n\
/*   Updated: 2018/12/01 21:39:06 by weilin           ###   ########.fr       */\n\
/*                                                                            */\n\
/* ************************************************************************** */\n"

echo "Generating ${function} tests"

# Header
echo "$ft_header" | sed "s/\&/$(printf %-30s ${header})/" > $header
echo "#ifndef $(echo $header | tr '[a-z].' '[A-Z]_')" >> $header
echo "# define $(echo $header | tr '[a-z].' '[A-Z]_')\n" >> $header

# Launcher
echo "$ft_header" | sed "s/\&/$(printf %-30s ${launcher})/" > $launcher
echo '#include "libunit.h"' >> $launcher
echo "#include \"$header\"\n" >> $launcher
echo "int\t\t${function}_launcher(void)\n{" >> $launcher
echo "\tt_array\t\ttest_list[1];" >> $launcher
echo "\n\ttest_list[0] = NEW_ARRAY(t_test);" >> $launcher

count=1
for input in 'pure_alpha|"first_string"|"second_string"' 'empty_s1|""|"why"'\
	'empty_s2|"are"|""' 'empty_both|""|""' 'null_s1|NULL|"you"' \
	'null_s2|"so handsome/beautiful"|NULL' 'null_both|NULL|NULL'
do
	name=$(echo $input | cut -d '|' -f1)_test
	s1=$(echo $input | cut -d '|' -f2)
	s2=$(echo $input | cut -d '|' -f3)
	filename=$(printf "%.2i" $count)_$name.c
	echo $filename
	echo "$ft_header" | sed "s/\&/$(printf %-30s ${filename})/" > $filename
	echo '#include "libft.h"' >> $filename
	echo '#include <string.h>\n' >> $filename
	echo "int\t\t${name}(void)\n{" >> $filename
	echo "\tchar\t*s1;" >> $filename
	echo "\tchar\t*s2;\n" >> $filename
	echo "\ts1 = ${s1};" >> $filename
	echo "\ts2 = ${s2};" >> $filename
	echo "\tif (${function}(s1, s2) == ft_${function}(s1, s2))" >> $filename
	echo "\t\treturn (0);" >> $filename
	echo "\telse" >> $filename
	echo "\t\treturn (-1);\n}" >> $filename
	echo "int\t\t${name}(void);" >> $header
	echo "\tload_test(test_list, \"$(echo $name | tr '_' ' ')\", &$name);" >> $launcher
	let count++
done

echo "\treturn (launch_tests(\"${function}\", test_list));\n}" >> $launcher
echo "\n#endif" >> $header
echo "Done"
