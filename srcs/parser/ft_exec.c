/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/27 16:43:17 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_runpipecmd(struct cmd *cmd, t_env *env)
{
	struct dopipe	*pipecmd;
	int				file_d[2];

	pipecmd = (struct dopipe *)cmd;
	if (pipe(file_d) < 0)
		ft_error("pipe error");
	if (fork1() == 0)
	{
		close(1); // first child closes stdout fd
		dup(file_d[1]); // changes the stdout by the file_d[1].
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->left, env);
	}
	if (fork1() == 0)
	{
		close(0); // second child closes stdin fd
		dup(file_d[0]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->right, env);
	}
	close(file_d[0]); //close fd of parent process
	close(file_d[1]);
	wait(0); // the parent process waits for the two children process
	wait(0);
}

void	ft_runcmd(struct cmd *cmd, t_env *env)
{
	struct doexec	*execcmd;
	struct doredir	*redircmd;

	if (cmd == 0)
		exit (1);
	if (cmd->type == EXEC)
	{
		execcmd = (struct doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		
		// else if (ft_strncmp(execcmd->names[0], "env", ft_strlen(execcmd->names[0])) == 0)
		// 	ft_env(env);
		// else if (ft_strncmp(execcmd->names[0], "pwd", ft_strlen(execcmd->names[0])) == 0)
		// 	ft_pwd(env);
		// else if (ft_strncmp(execcmd->names[0], "export", 6) == 0)
		// 	ft_export(NULL, env);
		// else if (ft_strncmp(execcmd->names[0], "unset", 5) == 0)
		// 	env = ft_unset(env, "USER");
		// 	//ft_unset(&env, "USER");
		else
		{
			printf("how could I possibly enter here with names[0]: %s\n", execcmd->names[0]);
			// printf("how could I possibly enter here with names[1]: %s\n", execcmd->names[1]);
			execvp(execcmd->names[0], execcmd->names);
		}
	}
	else if (cmd->type == REDIR)
	{
		redircmd = (struct doredir *)cmd;
		close(redircmd->fd);
		if (open(redircmd->file, redircmd->right) < 0)
			printf("redir %s failed\n", redircmd->file);
		exit (1);
	}
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd, env);
	exit (0);
}
