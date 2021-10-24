END="\033[0;0m"
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
WHITE="\033[1;37m"

echo -e $RED"#error Tester"$END

echo -e $YELLOW"#file error"$END
valgrind --leak-check=full --log-file=name_error.txt -v --error-limit=no ./fdf ./qwoierjxcv
echo -e $YELLOW"#width error"$END
valgrind --leak-check=full --log-file=width_error.txt -v --error-limit=no ./fdf ./test_maps/error_maps/width_error.fdf
echo -e $YELLOW"#width coordinate value error"$END
valgrind --leak-check=full --log-file=coordinate_error.txt -v --error-limit=no ./fdf ./test_maps/error_maps/width_coordinate_value_error.fdf
echo -e $YELLOW"#width color error"$END
valgrind --leak-check=full --log-file=color_error.txt -v --error-limit=no ./fdf ./test_maps/error_maps/width_color_value_error.fdf