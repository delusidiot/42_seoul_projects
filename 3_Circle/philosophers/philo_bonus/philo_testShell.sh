#!/bin/bash

END="\033[0;0m"
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
WHITE="\033[1;37m"

echo -e $CYAN"Start Tester!"$END
# short case
echo -e $GREEN"./philo 2 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 2 310 200 100;;
	[Nn]* ) echo -e $RED"skip died case"$END;;
	* ) echo "Please answer y or n.";;
esac

# 5 arg case
echo -e $GREEN"./philo 5 800 200 200 7"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 5 800 200 200 7;;
	[Nn]* ) echo -e $RED"skip 5 arg case"$END;;
	* ) echo "Please answer y or n.";;
esac

# infinity
echo -e $GREEN"./philo 5 800 200 200"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 4 410 200 200;;
	[Nn]* ) echo -e $RED"skip infinity case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $RED"End Tester!"$END
