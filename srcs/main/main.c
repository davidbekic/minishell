/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/22 18:39:03 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int	g_exit;

static int	ft_is_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[++i] != 0)
	{
		if (!((str[i]) == '\t' || (str[i]) == '\v'
				|| (str[i]) == '\r' || (str[i]) == '\n'
				|| (str[i]) == '\f' || (str[i]) == 32))
			return (0);
	}
	return (1);
}

static int	ft_getcmd(char **buf, t_env **env)
{
	char	*rl_copy;

	rl_copy = readline("🐚 ");
	ft_memset(*buf, 0, ft_strlen(*buf) + 1);
	ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
	if (*buf && **buf)
		add_history(rl_copy);
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

int	main(int ac, char **av, char **main_env)
{
	static char		*buf;
	t_env			*env;
	// int				exit_status;

	if ((ac > 1 && av[0][0] == '&') || !*main_env)
		exit(1);
	env = ft_init_env(main_env);
	// if (ft_strncmp(av[2], "exit", 4))
	// 	ft_runcmd(ft_parsecmd(buf), env);
	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		ft_runcmd(ft_parsecmd(av[2]), env);
		exit(0);
	}
	buf = (char *)ft_calloc(sizeof(char) * BUFFER_SIZE, 1);
	if (!buf | !env)
		ft_free_env(env, 1);
	ft_termios();
	ft_signals();
	while (ft_getcmd(&buf, &env) >= 0)
	{	
		if (ft_is_builtin(buf) || ft_is_isspace(buf))
			continue ;
		else if (fork() == 0)
			ft_runcmd(ft_parsecmd(buf), env);
		wait(0);
	}
	return (0);
}
