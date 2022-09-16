/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:18:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/16 14:15:49 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:18:25 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/16 11:18:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include "../../../../includes/minishell.h"

typedef struct s_gvars {
	int child_PID;
	int main_PID;
}	t_gvars;

t_gvars gvars;

void	ctrl_c_handler(int signum)
{
//	printf("pid_main: %d\npid_child: %d\n", gvars.main_PID, gvars.child_PID);
//	if (gvars.main_PID != 0)
//	{
//		kill(gvars.main_PID, SIGKILL);
//		gvars.main_PID = 0;
//	}
//	else if (gvars.main_PID == 0)
//	{
//		kill(gvars.main_PID, SIGKILL);
//	}
	printf("inside handler func. SIGNUM: %d\n", signum);
}

void	handler2(int signum)
{
	printf("INSIDE SCND HANDLER?\n");
	printf("SIGNUM: %d\n", signum);
}

int	main(int ac, char **av, char **main_env)
{
	int	i;
	int	pid;
	char	**args;
	t_env	*env;

	printf("ac: %d, av[1]: %s\n", ac, av[0]);
	env = ft_init_env(main_env);

	args = malloc(2000);
	args[0] = malloc(200);
	args[0] = "sleep";
	args[1] = malloc(200);
	args[1] = "20";
	args[2] = malloc(200);
	args[2] = NULL;
	args[3] = NULL;
	i = 0;
	signal(SIGINT, ctrl_c_handler);
//	signal(SIGINT, SIG_IGN);
	while (WIFEXITED(pid) != 0)
	{
		if (i == 0)
		{
				pid = fork();
			if (pid == 0)
			{
				signal(SIGINT, SIG_DFL);
				exit(130);
				if (ft_execve(env, args))
					printf("minishell: no such file or directory: %s\n", args[0]);
			}
			else
			{
				printf("value of PID in PARENT: %d\n", pid);
				wait(0);
				printf("fork done\n");
			}
			i++;
		}
//		free_env(env);
	}
}
