/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:04 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 14:30:20 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_alias(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_find_exec(t_env *env, char **names)
{
	char	tstr[BUFFER_SIZE];
	char	*path;
	char	*pstr;
	char	*cpath;

	path = ft_expand(env, "PATH");
	cpath = path;
	if (is_alias(names[0]))
	{
		while (cpath)
		{
			pstr = ft_strchrnul(cpath, ':');
			ft_memcpy(tstr, cpath, pstr - cpath);
			tstr[pstr - cpath] = '/';
			ft_memcpy(tstr + (pstr - cpath) + (pstr > cpath),
				names[0], ft_strlen(names[0]));
			execve(tstr, names, env->envp);
			ft_memset(tstr, 0, BUFFER_SIZE);
			cpath = pstr + 1;
			if (pstr[0] != ':')
				return (1);
		}
	}
	return (0);
}

int	ft_execve(t_env *env, char **names)
{
	int	ret;

	if (!(ft_strcmp(*names, "bash"))
		|| !(ft_strcmp(*names, "./minishell"))
		|| !(ft_strcmp(*names, "zsh")))
	{
		env->envp = ft_create_envp(env);
		if (!env->envp)
			ft_error("malloc error", 1);
	}
	if (is_alias(names[0]) && ft_expand(env, "PATH"))
	{
		ret = ft_find_exec(env, names);
		if (ret)
			ft_printf(2, "minishell: %s: command not found\n", names[0]);
	}
	else
	{
		ret = execve(names[0], names, env->envp) * -1;
		if (ret || !ft_expand(env, "PATH"))
			ft_printf(2, "minishell: %s: No such file or directory\n", names[0]);
	}
	return (ret);
}
