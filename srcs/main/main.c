/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 14:25:02 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int	g_exit;

int	main(int ac, char **av, char **main_env)
{
	static char		*buf;
	t_env			*env;
	int				pid;

	if ((ac > 1 && av[0][0] == '&') || !*main_env)
		exit(1);
	env = ft_init_env(main_env);
	buf = (char *)ft_calloc(sizeof(char) * BUFFER_SIZE, 1);
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		ft_memset(buf, 0, ft_strlen(buf) + 1);
		ft_memcpy(buf, av[2], ft_strlen(av[2]) + 1);
		ft_prompt_parser(&buf, env);
		ft_runcmd(ft_parsecmd(buf), env);
		exit(0);
	}
	if (!buf | !env)
		ft_free_env(env, 1);
	ft_termios();
	ft_signals();
	while (ft_getcmd(&buf, &env) >= 0)
	{
		if (ft_is_builtin(buf) || ft_is_space(buf))
			continue ;
		pid = fork();
		if (!pid)
		{
			kill(0, SIGUSR1);
			ft_termios_child();
			ft_runcmd(ft_parsecmd(buf), env);
		}
		wait(&pid);
		kill(0, SIGUSR2);
		if (WIFEXITED(pid))
			g_exit = WEXITSTATUS(pid);
		// if (WTERMSIG(pid) == 2 || WTERMSIG(pid) == 3)
		// 	g_exit = WTERMSIG(pid) + 128;
	}
	return (0);
}
