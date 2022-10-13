/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 18:21:53 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int g_exit;

static int	getcmd(char **buf, t_env *env)
{
	char	*rl_copy;
	
	ft_memset(*buf, 0, ft_strlen(*buf) + 1);
	*buf[0] = 'c';
	rl_copy = readline("🐚 ");
	ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
	if (*buf && **buf)
		add_history(rl_copy);
	if (ft_prompt_parser(buf, env))
	{
		perror("syntax error\n");
		g_exit = 258;
	}
	if (ft_is_builtin(*buf))
		return (ft_run_builtin(env, buf));
	return (1);
}

int	main(int ac, char **av, char **main_env)
{
	static char		*buf;
	t_env			*env;

	if ((ac > 1 && av[0][0] == '&') || !*main_env)
		exit(1);
	env = ft_init_env(main_env);
	if (!env)
		ft_free_env(env, 1);
	ft_termios();
	ft_signals();
	buf = (char *)ft_calloc(sizeof(char) * 4096, 1);
	if (!buf)
		ft_free_env(env, 1);
	while (getcmd(&buf, env) >= 0)
	{	
		if (ft_is_builtin(buf))
			continue;
		if (fork() == 0)			
			ft_runcmd(parsecmd(buf), env);
		wait(0);
	}
	return (0);
}
