/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:23 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/26 11:36:59 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_getcmd(char **buf, t_env **env)
{
	char	*rl_copy;

	rl_copy = readline("🐚 ");
	ft_memset(*buf, 0, ft_strlen(*buf) + 1);
	ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
	if (*buf && **buf)
		add_history(rl_copy);
	g_exit = ft_prompt_parser(buf, *env);
	free(rl_copy);
	if (g_exit)
	{
		ft_memset(*buf, 0, ft_strlen(*buf) + 1);
		return (1);
	}
	if (ft_is_builtin(*buf))
		return (ft_run_builtin(env, buf));
	return (1);
}