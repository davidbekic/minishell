/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:23 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/27 18:16:13 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_getcmd(char **buf, t_env **env)
{
	char	*rl_copy;

	ft_termios();
	ft_signals();
	rl_copy = readline("🐚 ");
	if (!rl_copy)
		ft_free_env(*env, 1);
	add_history(rl_copy);
	ft_memset(*buf, 0, ft_strlen(*buf) + 1);
	ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
	free(rl_copy);
	g_exit = ft_prompt_parser(buf, *env);
	if (g_exit)
	{
		ft_memset(*buf, 0, ft_strlen(*buf) + 1);
		return (1);
	}
	if (ft_is_builtin(*buf))
		return (ft_run_builtin(env, buf));
	return (1);
}
