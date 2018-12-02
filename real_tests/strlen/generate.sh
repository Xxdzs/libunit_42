# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 22:42:13 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 14:28:04 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

function="strlen"
header="${function}_tests.h"
launcher="00_${function}_launcher.c"
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

echo "Generating ${function} tests"

# Header
echo "$ft_header" > $header
echo "#ifndef $(echo $header | tr '[a-z].' '[A-Z]_')" >> $header
echo "# define $(echo $header | tr '[a-z].' '[A-Z]_')\n" >> $header

# Launcher
echo "$ft_header" > $launcher
echo '#include "libunit.h"' >> $launcher
echo "#include \"$header\"\n" >> $launcher
echo "int\t\t${function}_launcher(void)\n{" >> $launcher
echo "\tt_array\t\ttest_list[1];" >> $launcher
echo "\n\ttest_list[0] = NEW_ARRAY(t_test);" >> $launcher

count=1
for input in 'basic|"Hello World"' 'empty|""' "other|\"\\\v\\\nHello\\\0World\"" \
	"null|NULL"
do
	name=${input%%|*}_test
	str=${input#*|}
	filename=$(printf "%.2i" $count)_${name}.c
	echo $filename
	echo "$ft_header" > $filename
	echo '#include "libft.h"' >> $filename
	echo '#include <string.h>' >> $filename
	echo '#include <stddef.h>\n' >> $filename
	echo "int\t\t${name}(void)\n{" >> $filename
	echo "\tif (${function}(${str}) == ft_${function}(${str}))" >> $filename
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
