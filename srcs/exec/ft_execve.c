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

void	ctrl_c_handler2(int signum)
{
	printf("hombre\n");
}

static char	*ft_strchrnul(const char *s, int c)
{

	int i ;

	i = 0;

	while (s[i] != 0)

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
	path = getenv("PATH");
	cpath = path;
	if (is_alias(names[0]))
	{
		while (cpath)
		{
			pstr = ft_strchrnul(cpath, ':');
			// detta funkar eftersom pointers ar bara adresser i memory, 
			// sa pstr ar egentligen bara ett nummer som t.ex. 1000.
			// om vi sen ger tillbaka ptr + 14, ger vi tillbaka numret 1014
			// darfor blir pstr - cpath = 1014-1000 = 14
			// och darfor kan vi gora numeriska operationer med strings. strings AR nummer.
			ft_memcpy(tstr, cpath, pstr - cpath);
			tstr[pstr - cpath] = '/';
			ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), names[0], ft_strlen(names[0]));
			execve(tstr, names, NULL);
			memset(tstr, 0, 126);
			cpath = pstr + 1;
			if (pstr[0] != ':')
				return (1);
		}
		return (0);
	}
	else 
	{
		ret = execve(names[0], names, NULL);
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
