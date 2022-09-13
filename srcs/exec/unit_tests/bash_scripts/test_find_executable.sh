gcc ../mains/execve_test.c ../../ft_execve.c ../../../env/*.c ../../../commands/*.c ../../../../Libft/*.c
leaks -atExit -- ./a.out
