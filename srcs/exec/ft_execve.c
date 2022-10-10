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
			ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), names[0], ft_strlen(names[0]));
			execve(tstr, names, NULL);
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
	int		ret;
	char	shlvl[20];
	int		shlvl_int;

	ret = 0;
	shlvl_int = ft_atoi(ft_expand(env, "SHLVL")) + 1;
	ft_memcpy(shlvl, "SHLVL=", 7);
	ft_memcpy(shlvl + ft_strlen(shlvl), ft_itoa(shlvl_int), ft_strlen(ft_itoa(shlvl_int)) + 1);
	if (!(strcmp(names[0], "./minishell")))
	{	
		if (env->envp)
			free(env->envp);
		ft_update_var(shlvl, 6, env);
		env->envp = ft_create_envp(env);
		return (execve(names[0], names, env->envp));
	}
	else if (is_alias(names[0]))
		return (ft_find_exec(env, names));
	else
		return (execve(names[0], names, NULL));
}
