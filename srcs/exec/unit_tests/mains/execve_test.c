#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../../../../includes/minishell.h"



int	main(int ac, char **av, char **main_env)
{
	int	return_value;
	int	i;
	int	pid;
	char	**args;
	char	*command;
	t_env	*env;

	env = ft_init_env(main_env);

	args = malloc(2000);
	args[0] = malloc(200);
	args[0] = "../../../../../../../../../../../../bin/l";
	args[1] = malloc(200);
	args[1] = NULL;
	args[2] = malloc(200);
	args[2] = "test.txt";
	args[3] = NULL;
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		if (ft_execve(env, args))
			printf("no such file or directory: %s\n", args[0]);
	}
	else
	{
		printf("value of PID in PARENT: %d\n", pid);
		wait(&pid);
		printf("fork done\n");
	}
		free_env(env);

}
