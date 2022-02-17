make fclean
make debug
valgrind --leak-check=full --log-file=memcheck.txt -v --error-limit=no ./minishell