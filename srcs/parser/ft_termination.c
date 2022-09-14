/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termination.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:17:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/14 14:13:23 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

struct cmd	*terminate(struct cmd *cmd)
{
	struct doexec	*execcmd;
	struct doredir	*redircmd;
	struct dopipe	*pipecmd;
	int				iter;

	if (!cmd)
		return (0);
	if (cmd->type == EXEC)
	{
		iter = 0;
		execcmd = (struct doexec *)cmd;
		while (execcmd->names[iter])
		{
			*execcmd->end_names[iter] = 0;
			iter++;
		}
	}
	else if (cmd->type == REDIR)
	{
		redircmd = (struct doredir *)cmd;
		terminate(redircmd->cmd);
		*redircmd->efile = 0;
	}
	else if (cmd->type == PIPE)
	{
		pipecmd = (struct dopipe *)cmd;
		terminate(pipecmd->left);
		terminate(pipecmd->right);
	}
	return (cmd);
}
