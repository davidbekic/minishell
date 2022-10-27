/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:15:16 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/27 16:31:14 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit;

int	ft_run_builtin(t_env **env, char **buf)
{
	t_cmd		*builtin_cmd;
	t_doexec	*builtin_doexec;

	builtin_cmd = ft_builtparse(*buf);
	if (!builtin_cmd)
		ft_free_env(*env, 1);
	builtin_doexec = (t_doexec *) builtin_cmd;
	g_exit = ft_find_command(builtin_doexec, env);
	free(builtin_doexec);
	if (g_exit == -1)
		ft_free_env(*env, 1);
	return (0);
}
