gcc ../init_env.c && ./a.out > or_out
gcc ./init_env_test.c && ./a.out > my_out
diff or_out my_out
