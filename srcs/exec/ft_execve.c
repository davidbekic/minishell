/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:04 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/13 18:42:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <ctype.h>

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

static char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			break ;
		s++;
	}
	return ((char *)s);
}

static int	ft_find_exec(t_env *env, char **names)
{
	char	tstr[126];
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
			memset(tstr, 0, 126);
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

	if (!(strcmp(*names, "bash"))
		|| !(strcmp(*names, "./minishell"))
		|| !(strcmp(*names, "zsh")))
	{
		env->envp = ft_create_envp(env);
		if (!env->envp)
		{
			ft_putstr_fd("malloc fail, please try again\n", 2);
			return (1);
		}
	}
	if (is_alias(names[0]))
	{
		ret = ft_find_exec(env, names);
		if (ret)
			ft_putstr_fd("minishell: command not found\n", 2);
	}
	else
	{
		ret = execve(names[0], names, env->envp);
		if (ret)
			ft_putstr_fd("minishell: No such file or directory\n", 2);
	}
	return (ret);
}
