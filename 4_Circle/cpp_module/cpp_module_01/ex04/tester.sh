#!/bin/bash

RED="\033[1;31m"
GRN='\033[0;32m'
BLU='\033[0;34m'
END='\033[0m'

make

echo -e $BLU
cat -n ./testFiles/fileA
echo -e $END

read -p "start this? (yn)" yn

case $yn in
	[Yy]* ) ./replace ./testFiles/fileA empty none
			echo -e $GRN
			cat -n ./testFiles/fileA.replace
			echo -e $END;;
	[Nn]* ) echo -e $RED"skip this!"$END;;
	* ) echo "Please y or n";;
esac