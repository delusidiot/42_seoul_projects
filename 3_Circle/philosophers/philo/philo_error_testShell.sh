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
echo -e $GREEN"./philo 2 2 2"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 2 2 2;;
	[Nn]* ) echo -e $RED"skip lack of arg case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"./philo -2 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo -2 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg minus case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"./philo 2a 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 2a 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg in alpha case"$END;;
	* ) echo "Please answer y or n.";;
esac

echo -e $GREEN"./philo 2000000000000 310 200 100"$END
read -p "start this?(yn)" yn
case $yn in
	[Yy]* )./philo 2000000000000 310 200 100;;
	[Nn]* ) echo -e $RED"skip arg to large case"$END;;
	* ) echo "Please answer y or n.";;
esac