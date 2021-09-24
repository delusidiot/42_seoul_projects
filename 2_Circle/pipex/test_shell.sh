RED="\033[1;31m"
END="\033[0;0m"
GREEN="\033[1;32m"
comp() {
	printf "$RED"; diff -u $1 $2; printf "$END"
	if [ $? -eq 0 ]; then
		printf "$GREEN""OK !$END\n"
	fi
}
echo "< infile cat | wc -c > outfile"
< infile cat | wc -c > answer
./pipex infile "cat" "wc -c" outfile
comp answer outfile
rm answer outfile

echo "< infile grep Lorem | awk '{count++} END {print count}' > outfile"
< infile grep Lorem | awk '{count++} END {print count}' > answer
./pipex infile "grep Lorem" "awk '{count++} END {print count}'" outfile
comp answer outfile
rm answer outfile
