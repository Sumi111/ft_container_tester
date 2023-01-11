#!/bin/bash

DEFAULT=$(tput sgr0)
RED='\033[1;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
PURPLE='\033[1;35m'
CYAN='\033[0;36m'
#####################################################################################################################

TEST_DIR=test_reports
FT_STACK=ft_stack
STD_STACK=std_stack
FT_VECTOR=ft_vector
STD_VECTOR=std_vector

CC=c++
CFLAGS='-Wall -Wextra -Werror'
VALGRIND=valgrind
VFLAGS='--leak-check=full --show-leak-kinds=all'
RM='rm -rf'
LOG=compilation.log

#####################################################################################################################

getEmoji () {
	# 1=integer
	emoji='';
	case $1 in
		0) emoji="${GREEN}✅";;
		1) emoji="${RED}❌";;
		2) emoji="${RED} 🟢";;
		2) emoji="${RED}🔴";;
		
	esac
	printf "${BOLD}${emoji}${EOC}"
}


#####################################################################################################################

execute_and_redirect_output() {
	for file in $TEST_DIR/$1/*.o; do
		# compile the object files 
		$CC $CFLAGS $file -o ${file%%.o}
		# execute them & redirect it to a text file
		./${file%%.o} > ${file%%.o}.txt

		# (if OS is linux) run with valgrind and redirect output to a text file located in a different directory

		# delete object and executable file
		rm $file ${file%%.o}
	done
	printf "\033[A\033[2K\r"
}


print_test_results() {
	c=$(echo "$3" | awk '{print toupper($0)}')
	printf $PURPLE"\t$c $DEFAULT\n"
	# for each file in test_reports/container_type, do the following 
	for file in $TEST_DIR/$1/*.txt; do
		printf $CYAN'%-40s' " • $(basename -- $file .txt)$DEFAULT"
		if [  $TEST_DIR/$2/${file##*/} ]; then		#check to seee if compiled
			echo -ne "Compiled: $(getEmoji 0) $DEFAULT |  "
			diff <(sed '$d' $file) <(sed '$d' $TEST_DIR/$2/${file##*/}) > diff # 
			if [ -s diff ]; then
				echo -ne "Result: $(getEmoji 1) $DEFAULT"
			else
				echo -ne "Result: $(getEmoji 0) $DEFAULT |  "
				x=$(tail -n 1 $TEST_DIR/$2/${file##*/})
				y=$(tail -n 1 $file)
				z=$(echo "$y / $x" | bc)
				echo -ne "FT Time:$YELLOW"  $x ms"$DEFAULT |  "
				echo -ne "STD Time:$YELLOW" $y ms"$DEFAULT |  "
				if (( $z < 20 )); then
					echo -ne " Within_limit: $(getEmoji 2) $DEFAULT "
				else
					echo -ne " Within_limit: $(getEmoji 1) $DEFAULT "
				fi

			fi
			# check_valgrind_report $TEST_DIR/$3/${file##*/}
			rm diff
		else
			printf "Compiled:$RED KO $DEFAULT |  Result:$RED KO $DEFAULT"
		fi
		echo
	done
	if [ -s diff ]; then
		echo -e $YELLOW"Check the outputs in the test_reports directory"$DEFAULT
	fi
}


start_tests() {
	printf "\033[A\033[2K\r"

	echo -e $YELLOW"Turning ft::$1 objects into executables & saving their output to a .txt file"$DEFAULT
	execute_and_redirect_output $2
	echo -e $YELLOW"Turning std::$1 objects into executables & saving their output to a .txt file"$DEFAULT
	execute_and_redirect_output $3

	print_test_results $3 $2 $1
}

#####################################################################################################################
if [ $# -ne 1 ]; then
	echo -e $RED"Wrong format!! Try:  bash grademe.sh <container_type>"$DEFAULT
	echo -e $CYAN"<container_type> : vector, stack, map"$DEFAULT
	echo -e $CYAN"<others> : clean, all"$DEFAULT
	exit 1
fi

if [ $1 == "vector" ]; then
	echo -e $GREEN"TESTING VECTOR"$DEFAULT
	make fclean && make -k vector
	start_tests "vector" $FT_VECTOR $STD_VECTOR

elif [ $1 == "stack" ]; then
	echo -e $GREEN"TESTING STACK"$DEFAULT
	make fclean && make -k stack
	start_tests "stack" $FT_STACK $STD_STACK

elif [ $1 == "map" ]; then
	echo -e $GREEN"TESTING MAP"$DEFAULT

elif [ $1 == "clean" ]; then
	echo -e $GREEN"Cleaning"$DEFAULT
	make fclean
	echo -e $GREEN"Done!!"$DEFAULT


elif [ $1 == "all" ]; then
	echo -e $YELLOW"TESTING ALL 3 CONTAINERS"$DEFAULT
	echo -e $GREEN"TESTING VECTOR"$DEFAULT
	make fclean && make -k vector
	start_tests "vector" $FT_VECTOR $STD_VECTOR
	echo -e $GREEN"TESTING STACK"$DEFAULT
	make -k stack
	start_tests "stack" $FT_STACK $STD_STACK
	echo -e $GREEN"TESTING MAP"$DEFAULT

else
	echo -e $RED"Unknown container_type!!"$DEFAULT
	exit 1

fi