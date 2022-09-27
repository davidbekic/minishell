/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:18:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/27 16:32:08 by dbekic           ###   ########.fr       */
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
	unsigned char g_exit_code;
	int main_PID;
}	t_gvars;

t_gvars gvars;

void	ctrl_c_handler(int signum)
{
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
	args[0] = "ls";
	args[1] = malloc(200);
	args[1] = "\"\"";
	args[2] = malloc(200);
	args[2] = NULL;
	args[3] = NULL;
	i = 0;
//	signal(SIGINT, ctrl_c_handler);
	// signal(SIGQUIT, ctrl_c_handler);	
	// signal(SIGINT, SIG_IGN);
	 while (1)
	 {
		if (i == 0)
		{
			// CHILD PROCESS
			pid = fork();
			if (pid == 0)
			{
				int ret;
				printf("hellooo\n");
				signal(SIGINT, SIG_DFL);
				ret = ft_execve(env, args);
				if (ret != 0)
					printf("minishell: no such file or directory: %s\n", args[0]);
				exit(4);
				return (ret);
			}
			else
			{
				printf("value of PID in PARENT: %d\n", pid);
				printf("pid in parent: %d\n", pid);
				wait(&pid);
				if (WIFEXITED(pid))
				{
					printf("WIFEXITED is true\n");
					gvars.g_exit_code = WEXITSTATUS(pid);
				}
				if (WIFSIGNALED(pid))
				{
					printf("WIFSIGNALED is true\n");
					gvars.g_exit_code = WTERMSIG(pid) + 128;		
				}			
				printf("exit_status of child %d\n", gvars.g_exit_code);
				printf("fork done\n");
				//exit (0);
			}
			i++;
		}
	 }
	// free_env(env);
//	return (gvars.g_exit_code);
	exit(gvars.g_exit_code);
}
