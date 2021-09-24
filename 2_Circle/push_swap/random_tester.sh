#!/bin/bash

ARG=`ruby -e "puts (1..20).to_a.shuffle.join(' ')"`;
echo "========================"
echo "Arguments : $ARG"
echo "========================"
#./push_swap $ARG | wc -l
#./push_swap $ARG | ./checker $ARG;
./push_swap $ARG
