/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:08:29 by davidbekic        #+#    #+#             */
/*   Updated: 2022/10/27 23:20:11 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_word_to_lower(char **command)
{
	int		i;

	i = -1;
	while (command[0][++i])
		command[0][i] = ft_tolower(command[0][i]);
}

static int	ft_find_lower_command(t_doexec **execcmd, t_env **env, char *buf)
{
	if (!(ft_strcmp((*execcmd)->names[0], "export")))
	{
		g_exit = ft_export((*execcmd)->names, *env);
		if (g_exit == -1)
			return (g_exit);
		else
			return (g_exit);
	}
	else if (!(ft_strcmp((*execcmd)->names[0], "unset")))
		return (ft_unset((*execcmd)->names, env));
	else if (!(ft_strcmp((*execcmd)->names[0], "exit")))
	{
		free(buf);
		ft_free_env(*env, 0);
		ft_exit((*execcmd));
	}
	return (0);
}

int	ft_find_command(t_doexec *execcmd, t_env **env, char *buf)
{
	int	ret;

	ret = 0;
	// if (!(ft_strcmp(execcmd->names[0], "export")))
	// {
	// 	return (ft_export(execcmd->names, *env));
	// 	if (g_exit == -1)
	// 		return (g_exit);
	// 	else
	// 		return (ret);
	// }
	// else if (!(ft_strcmp(execcmd->names[0], "unset")))
	// 	return (ft_unset(execcmd->names, env));
	// else if (!(ft_strcmp(execcmd->names[0], "exit")))
	// {
	// 	free(buf);
	// 	ft_free_env(*env, 0);
	// 	ft_exit(execcmd);
	// }
	ret = ft_find_lower_command(&execcmd, env, buf);
	if (ret)
		return (ret);
	ft_word_to_lower(execcmd->names);
	if (!(ft_strcmp(execcmd->names[0], "env")))
		ret = ft_env(*env, execcmd->names);
	else if (!(ft_strcmp(execcmd->names[0], "echo")))
		ret = ft_echo(execcmd->names);
	else if (!(ft_strcmp(execcmd->names[0], "cd")))
		ret = ft_cd(*env, execcmd->names);
	else if (!(ft_strcmp(execcmd->names[0], "pwd")))
		ret = ft_pwd(*env);
	else
		ret = ft_execve(*env, execcmd->names);
	return (ret);
}
