gcc ../mains/general_main.c ../../../commands/*.c ../../*.c && leaks -atExit -- ./a.out
gcc ../mains/real_unset_main.c ../../../commands/*.c ../../*.c && leaks -atExit -- ./a.out
gcc ../mains/real_export_main.c ../../../commands/*.c ../../*.c && leaks -atExit -- ./a.out
gcc ../mains/real_env_main.c ../../../commands/*.c ../../*.c && leaks -atExit -- ./a.out
gcc ../mains/real_unset_main.c ../../*.c ../../../commands/*.c && leaks -atExit -- ./a.out
rm -rf a.out