/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:15:16 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/18 22:33:14 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_builtin(t_env *env, char **buf)
{
	cmd		*builtin_cmd;
	doexec		*builtin_doexec;
	char	temp[BUFFER_SIZE];

	ft_memcpy(temp, *buf, ft_strlen(*buf) + 1);
	builtin_cmd = builtparse(temp);
	if (!builtin_cmd)
		ft_free_env(env, 1);
	builtin_doexec = (doexec *) builtin_cmd;
	ft_find_command(builtin_doexec, env);
	free(builtin_doexec);
	return (0);
}
