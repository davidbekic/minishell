cd Libft ; Make
cd ..
gcc -LLibft -lft -lreadline srcs/commands/echo.c srcs/commands/env.c srcs/commands/export.c srcs/commands/pwd.c srcs/commands/unset.c srcs/env/ft_create_elem.c srcs/env/ft_expand.c srcs/env/ft_find_elem.c srcs/env/ft_find_key_value.c srcs/env/ft_free_env.c srcs/env/ft_init_env.c srcs/exec/ft_execve.c srcs/parser/ft_build.c srcs/parser/ft_exec.c srcs/parser/ft_parser.c srcs/parser/ft_termination.c srcs/parser/ft_utils.c srcs/parser/main.c srcs/env/ft_var_name_check.c srcs/parser/prompt_parser.c
./a.out
