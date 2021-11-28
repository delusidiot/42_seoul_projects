#!/bin/zsh

END="\033[0;0m"
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
WHITE="\033[1;37m"

target="philo"

if [ "$#" -ne 2 ]; then
    echo "Usage: tester.sh <Project Folder> <Test Type>"
    echo "\tType 1: test philo only"
    echo "\tType 2: test philo_bonus only"
	exit
fi

if [ "$2" -eq 1 ]; then
	target="philo"
fi
if [ "$2" -eq 2 ]; then
	target="philo_bonus"
fi
if [ "$2" -gt 2 -o "$2" -lt 1 ]; then
	echo "[Error]: Wrong Arguments"
	exit
fi
		

echo -e $CYAN"Start Tester!"$END
# short case
echo -e $GREEN"$target 2 2 2"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* ) $1$target/$target 2 2 2;;
	[Nn]* ) echo -e $RED"skip lack of arg case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"$target -2 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* ) $1$target/$target -2 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg minus case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"./philo 2a 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* ) $1$target/$target 2a 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg in alpha case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"$target 3000000000 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* ) $1$target/$target 2000000000000 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg to large case"$END;;
	* ) echo "Please answer y or n.";;
esac
