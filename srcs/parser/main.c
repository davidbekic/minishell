/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/06 19:09:55 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"


static int	getcmd(char **buf, t_env *env)
{
	char *rl_copy;

	rl_copy = NULL;
	while (1)
	{
		ft_memset(*buf, 0, ft_strlen(*buf));
		rl_copy = readline("🐚 ");
		ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
		if (*buf && **buf)
			add_history(rl_copy);
		if (ft_prompt_parser(buf, env))
		{
			perror("syntax error\n");
			return (258);
		}
		if (ft_strncmp(*buf, "exit", ft_strlen(*buf)) == 0)
			return (-1);
		else if (!ft_strncmp(*buf, "env", 3))
			ft_env(env);
		else if (!ft_strncmp(*buf, "pwd", 3))
			ft_pwd(env);
		// else if (ft_strncmp(*buf, "export1", 7) == 0)
		// 	ft_export("USER=kuksugareballe", env);
		// else if (ft_strncmp(*buf, "export2", 7) == 0)
		// 	ft_export(NULL, env);
		else if (ft_strncmp(*buf, "unset", 5) == 0)
			ft_unset("USER", env);

		else 
			break ;
	}	
	return (0);
}

int	main(int ac, char **av, char **main_env)
{
	static char	*buf;
	t_env		*env;

	if (ac > 1 && av[0][0] == '&')
		exit(1);
	printf("main_env[0]: %s\n", main_env[0]);
	env = ft_init_env(main_env);
	
	buf = (char *)malloc(sizeof(char) * 4096);
	if (!buf)
		exit (-1);
	while (getcmd(&buf, env) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			buf[ft_strlen(buf)] = 0;
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
			ft_runcmd(parsecmd(buf), env);
		//printf("returned value %d\n", WEXITSTATUS(0));
		wait(0);
	}
	printf("reach here?\n");
	ft_free_env(env);
	free(buf);
	free(env->envp);
	return (0);
}
