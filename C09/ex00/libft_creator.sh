rm -rf libft.a
gcc -c -Wall -Wextra -Werror *.c
ar rc libft.a *.o
rm -rf *.o
