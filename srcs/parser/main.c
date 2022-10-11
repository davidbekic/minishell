/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/11 16:51:55 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static int	ft_is_builtin(char *buf)
{
	int	marker;
	int	i;
	char	*head;
	char	comparison_str[4096];
	static char	*built_ins[400] = {"echo", "export", "unset", "pwd", "cd", "exit", "env"};
	
	ft_bzero(comparison_str, 4096);
	marker = 0;
	i = 0;
	head = buf;
	while ((*buf))
	{
		if ((*buf) == '|' || (*buf) == '<' || (*buf) == '>')
			return (0);
		buf++;
	}
	buf = head;
	while ((*buf))
	{
		if (*buf == 32 || *buf == 0)
			break ;
		buf++;
		marker++;
	}
	buf = head;
	while (built_ins[++i - 1])
	{
		if (!(strcmp(ft_memcpy(comparison_str, buf, marker), built_ins[i - 1])))
			return (1);
	}
	return (0);
}

static int	ft_run_builtin(t_env *env, char **buf)
{
	cmd		*builtin_cmd;
	doexec	*builtin_doexec;
	char 	temp[40096];

	ft_memcpy(temp, *buf, ft_strlen(*buf) + 1);
	builtin_cmd = builtparse(temp);
	builtin_doexec = (doexec *) builtin_cmd;
	if (!(ft_strncmp(builtin_doexec->names[0], "echo", 4)))
		ft_echo(builtin_doexec->names);
	if (!(ft_strncmp(builtin_doexec->names[0], "export", 6)))
		ft_export(builtin_doexec->names, env);
	if (!(ft_strncmp(builtin_doexec->names[0], "unset", 5)))
		ft_unset(builtin_doexec->names, &env);
	if (!(ft_strncmp(builtin_doexec->names[0], "exit", 4)))
	{
		ft_free_env(env);
		free(builtin_doexec);
		ft_exit(builtin_doexec->names);
	}
	if (!(ft_strncmp(builtin_doexec->names[0], "cd", 2)))
	{
		if (ft_cd(env, builtin_doexec->names))
			printf("minishell: cd: %s: No such file or directory\n", *(builtin_doexec->names + 1));
	}
	if (!(ft_strncmp(builtin_doexec->names[0], "env", 3)))
		ft_env(env, builtin_doexec->names);
	if (!(ft_strncmp(builtin_doexec->names[0], "pwd", 3)))
		ft_pwd(env);
	free(builtin_cmd);
	return (0);
	
}

static int	getcmd(char **buf, t_env *env)
{
	char	*rl_copy;
	
	ft_memset(*buf, 0, ft_strlen(*buf) + 1);
	*buf[0] = 'c';
	//printf("strlen(rl_copy): %zu\n", ft_strlen(rl_copy));
	rl_copy = readline("🐚 ");
	ft_memcpy(*buf, rl_copy, ft_strlen(rl_copy) + 1);
	if (*buf && **buf)
		add_history(rl_copy);
	if (ft_prompt_parser(buf, env))
	{
		perror("syntax error\n");
		return (258);
	}
	if (ft_is_builtin(*buf))
		return (ft_run_builtin(env, buf));
	return (1);
}

int	main(int ac, char **av, char **main_env)
{
	static char		*buf;
	unsigned char	infinite_loop;
	t_env			*env;


	if ((ac > 1 && av[0][0] == '&') || !*main_env)
		exit(1);
	env = ft_init_env(main_env);
	infinite_loop = 1;
	
	buf = (char *)ft_calloc(sizeof(char) * 40096, 1);
	if (!buf)
		exit (-1);	
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
