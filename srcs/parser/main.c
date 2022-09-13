/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/13 18:00:23 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static int	getcmd(char **buf, int size, t_env *env)
{
	ft_memset(*buf, 0, size);
	*buf = readline("$ ");
	add_history(*buf);
	if (ft_strncmp(*buf, "exit", ft_strlen(*buf)) == 0)
		return (-1);
	if (ft_strncmp(*buf, "pwd", ft_strlen(*buf)) == 0)
		ft_pwd(env);
	if (ft_strncmp(*buf, "env", ft_strlen(*buf)) == 0)
		ft_env(env);
	if (ft_strncmp(*buf, "export", ft_strlen(*buf)) == 0)
	{
		printf("seriouslY NOT exporting RIGHT NOW?\n");
		ft_export(ft_find_key("HELLO=THERE"), ft_find_value("HELLO=THERE"), env);
	}
	return (0);
}

int	main(int ac, char **av, char **main_env)
{
	static char	*buf;
	t_env *env;

	printf("ac: %d\nav[0]: %s\n", ac, av[0]);

	env = ft_init_env(main_env);
	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		exit (-1);
	while (getcmd(&buf, sizeof(buf), env) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			printf("entro en cd\n");
			buf[ft_strlen(buf)] = 0;
			printf("strlen %lu y directorio %s\n", ft_strlen(buf), buf + 3);
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
		{
			printf("dentro hijo\n");
			ft_runcmd(parsecmd(buf));
			printf("hola fuera\n");
		}
		wait(0);
		printf("buf %s\n", buf);
	}
	return (0);
}
