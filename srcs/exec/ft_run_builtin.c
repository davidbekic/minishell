/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:15:16 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/13 18:43:31 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_builtin(t_env *env, char **buf)
{
	cmd		*builtin_cmd;
	doexec		*builtin_doexec;
	char	temp[4096];

	ft_memcpy(temp, *buf, ft_strlen(*buf) + 1);
	builtin_cmd = builtparse(temp);
	if (!builtin_cmd)
		ft_free_env(env, 1);
	builtin_doexec = (doexec *) builtin_cmd;
	if (!(ft_strncmp(builtin_doexec->names[0], "echo", 4)))
		g_exit = ft_echo(builtin_doexec->names);
	if (!(ft_strncmp(builtin_doexec->names[0], "env", 3)))
		g_exit = ft_env(env, builtin_doexec->names);
	if (!(ft_strncmp(builtin_doexec->names[0], "export", 6)))
		g_exit = ft_export(builtin_doexec->names, env);
	if (!(ft_strncmp(builtin_doexec->names[0], "unset", 5)))
		g_exit = ft_unset(builtin_doexec->names, &env);
	if (!(ft_strncmp(builtin_doexec->names[0], "exit", 4)))
	{
		// ft_free_env(env, 0);
		// free(builtin_doexec);
		// free(*buf);
		ft_exit(builtin_doexec->names);
	}
	if (!(ft_strncmp(builtin_doexec->names[0], "cd", 2)))
		g_exit = ft_cd(env, builtin_doexec->names);
	if (!(ft_strncmp(builtin_doexec->names[0], "pwd", 3)))
		ft_pwd(env);
	free(builtin_doexec);
	return (0);
}
