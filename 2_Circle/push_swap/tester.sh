#!/bin/bash

cat ./args.txt | while read ARG
do
	echo "input : $ARG"
	#./push_swap $ARG
	./push_swap $ARG  | ./checker $ARG
	#./push_swap $ARG  | wc -l
done
