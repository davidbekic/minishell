/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 11:57:14 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static void	ft_exit_code_listener(int pid1, int pid2)
{
	printf("pid1: %d\npid2: %d\n", pid1, pid2);
	printf("WIF: %d\n", WIFEXITED(pid2));
	// exit(WIFEXITED(pid2));	
	if (WIFEXITED(pid2))
		g_exit = WEXITSTATUS(pid2);
	else if (WIFSIGNALED(pid2))
	{
		printf("entering with WTERMSIG: %d\n", WTERMSIG(pid2));
		if (WTERMSIG(pid2) == 2 || WTERMSIG(pid2) == 3)
			g_exit = WTERMSIG(pid2) + 128;
	}
}

static void	ft_exec_pipes(int file_d[2], t_dopipe *pipecmd,
				int close_int, t_env *env)
{
	close(close_int);
	dup(file_d[close_int]);
	close(file_d[0]);
	close(file_d[1]);
	if (close_int)
		ft_runcmd(pipecmd->left, env);
	else
		ft_runcmd(pipecmd->right, env);
}

static void	ft_runpipecmd(t_cmd *cmd, t_env *env)
{
	t_dopipe	*pipecmd;
	int			pid1;
	int			pid2;
	int			file_d[2];

	pipecmd = (t_dopipe *)cmd;
	if (pipe(file_d) < 0)
		ft_error("pipe error", 1);
	pid1 = ft_fork1();
	if (!pid1)
		ft_exec_pipes(file_d, pipecmd, 1, env);
	if (WIFSIGNALED(pid1))
		g_exit = WTERMSIG(pid1) + 128;
	pid2 = ft_fork1();
	if (!pid2)
		ft_exec_pipes(file_d, pipecmd, 0, env);
	close(file_d[0]);
	close(file_d[1]);
	// wait(&pid1);
	// wait(&pid2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	ft_exit_code_listener(pid1, pid2);
}

static void	ft_runredir(t_cmd *cmd, t_env *env)
{
	t_doredir		*redircmd;
	t_cmd			*srcmd[_POSIX_OPEN_MAX];
	int				j;

	j = 1;
	ft_p_struct(cmd, srcmd);
	redircmd = (t_doredir *)srcmd[0];
	if (redircmd->right & O_RDWR)
		ft_heredoc(cmd, env);
	redircmd = (t_doredir *)srcmd[j];
	while (redircmd->type == 2)
	{
		redircmd = (t_doredir *)srcmd[j];
		if ((access(redircmd->file, F_OK)) == 0)
		{
			if (open(redircmd->file, redircmd->right) < 0)
				ft_error("open failed", 1);
		}
		else
			if ((open(redircmd->file, redircmd->right, RWRR)) < 0)
				ft_error("open error", 1);
		redircmd = (t_doredir *)srcmd[++j];
	}
	ft_redir_exec(srcmd[0]);
	ft_runcmd(srcmd[j], env);
}

void	ft_runcmd(t_cmd *cmd, t_env *env)
{
	t_doexec	*execcmd;

	signal(SIGQUIT, SIG_DFL);
	if (cmd == 0)
		exit (1);
	if (cmd->type == EXEC)
	{
		execcmd = (t_doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		g_exit = ft_find_command(execcmd, &env);
	}
	else if (cmd->type == REDIR)
		ft_runredir(cmd, env);
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd, env);
	exit (g_exit);
}
