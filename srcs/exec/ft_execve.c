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


int	ft_execve(t_env *env, char **names)
{
	char	tstr[126];
	char	*path;
	char	*pstr;
	char	*cpath;
	int	ret;

	ret = 1;
	printf("env->name: %s\n", env->value);
	path = ft_expand(env, "PATH");
	//path = getenv("PATH"); // we can't use this because of potential deletion of PATH variable
	//memcpy(names[1], "122", 2);
	cpath = path;
	//env->envp = ft_create_envp(env);
	printf("env->envp[0]: %s\n", env->envp[0]);
	if (is_alias(names[0]))
	{
		while (cpath)
		{
			pstr = ft_strchrnul(cpath, ':');
			ft_memcpy(tstr, cpath, pstr - cpath);
			tstr[pstr - cpath] = '/';
			ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), names[0], ft_strlen(names[0]));
			execve(tstr, names, env->envp);
			memset(tstr, 0, 126);
			cpath = pstr + 1;
			if (pstr[0] != ':')
				return (1);
		}
		return (0);
	}
	else 
	{
		ret = execve(names[0], names, env->envp);
		if (ret)
			return (1);
		else
			return (0);
	}
}



// int	ft_execve(t_env *env, char **names)
// {
// 	char	**paths;
// 	char	*buffer;
// 	int	i;
// 	int	ret;

// 	ret = 1;
// 	i = 0;
// 	paths = NULL;
// 	printf("names[1]: %s\n", names[1]);
// 	if (is_alias(names[0]))
// 	{
// 		paths = ft_split(ft_expand(env, "PATH"), ':');
// 		while (ret != 0)
// 		{
// 			buffer = ft_strdup(paths[i]);
// 			free(paths[i]);
// 			strlcat(buffer, "/", ft_strlen(paths[i]) + ft_strlen("/") + 1);
// 			strlcat(buffer, names[0], ft_strlen(buffer) + ft_strlen(names[0]) + 1);
// 			ret = execve(buffer, names, NULL);
// 			free(buffer);
// 			i++;
// 			if (paths[i] == NULL)
// 				return (1);
// 		}
// 		free (paths);
// 		return (0);
// 	}
// 	else 
// 	{
// 		ret = execve(names[0], names, NULL);
// 		if (ret)
// 			return (1);
// 		else
// 			return (0);
// 	}
// }
