RED="\033[1;31m"
END="\033[0;0m"
GREEN="\033[1;32m"
comp() {
	printf "$RED"; diff -u $1 $2; printf "$END"
	if [ $? -eq 0 ]; then
		printf "$GREEN""OK !$END\n"
	fi
}
echo "< infile cat | grep Lorem | wc -l > outfile"
< infile cat | grep Lorem | wc -l > answer
./pipex infile "cat" "grep Lorem" "wc -l" outfile
comp answer outfile
rm answer outfile
