/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/19 13:49:27 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static void	ft_runpipecmd(struct cmd *cmd, t_env *env)
{
	struct dopipe	*pipecmd;
	int				file_d[2];

	pipecmd = (struct dopipe *)cmd;
	if (pipe(file_d) < 0)
		ft_error("pipe error", 1);
	if (fork1() == 0)
	{
		close(1);
		dup(file_d[1]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->left, env);
	}
	if (fork1() == 0)
	{
		close(0);
		dup(file_d[0]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->right, env);
	}
	close(file_d[0]);
	close(file_d[1]);
	wait(0);
	wait(0);
}

static void	ft_runredir(struct cmd *cmd, t_env *env)
{
	struct doredir	*redircmd;
	struct cmd		*srcmd[_POSIX_OPEN_MAX];
	int				j;

	j = 1;
	p_struct(cmd, srcmd);
	redircmd = (struct doredir *)srcmd[0];
	if (redircmd->right & O_RDWR)
	{
		printf("running heredoc\n");
		ft_heredoc(cmd, env);
	}
	redircmd = (struct doredir *)srcmd[j];
	while (redircmd->type == 2)
	{
		redircmd = (struct doredir *)srcmd[j];
		if ((access(redircmd->file, F_OK)) == 0)
		{
			if (open(redircmd->file, redircmd->right) < 0)
				ft_error("open failed", 1);
		}
		else
			if ((open(redircmd->file, redircmd->right, RWRR)) < 0)
				ft_error("open error", 1);
		redircmd = (struct doredir *)srcmd[++j];
	}
	ft_redir_exec(srcmd[0]);
	ft_runcmd(srcmd[j], env);
}

void	ft_runcmd(struct cmd *cmd, t_env *env)
{
	struct doexec	*execcmd;
	int				ret;

	ret = 0;
	if (cmd == 0)
		exit (1);
	if (cmd->type == EXEC)
	{
		execcmd = (struct doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		ret = ft_find_command(execcmd, env);
		printf("exec %s failed\n", execcmd->names[0]);
	}
	else if (cmd->type == REDIR)
		ft_runredir(cmd, env);
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd, env);
	exit (ret);
}



























// void	ft_runcmd(struct cmd *cmd, t_env *env)
// {
// 	struct doexec	*execcmd;
// 	struct doredir	*redircmd;
// 	int				ret;

// 	ret = 0;
// 	if (cmd == 0)
// 		exit (1);
// 	if (cmd->type == EXEC)
// 	{
// 		execcmd = (struct doexec *)cmd;
// 		if (execcmd->names[0] == 0)
// 			exit (1);
// 		ret = ft_find_command(execcmd, env);
// 		if (!(ft_strcmp(execcmd->names[0], "export")))
//         	free(env);
// 	}
// 	else if (cmd->type == REDIR)
// 	{
// 		redircmd = (struct doredir *)cmd;
// 		close(redircmd->fd);
// 		if (open(redircmd->file, redircmd->right) < 0)
// 			printf("redir %s failed\n", redircmd->file);
// 		exit (1);
// 	}
// 	else if (cmd->type == PIPE)
// 		ft_runpipecmd(cmd, env);
// 	exit (ret);
// }
