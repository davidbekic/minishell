#include "../../includes/minishell.h"

void	ft_execve(t_env *env, char **names)
{
	char	**paths;
	char	*buffer;
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	paths = ft_split(ft_expand(env, "PATH"), ':');
	while (ret != 0)
	{
		buffer = ft_strdup(paths[i]);
		free(paths[i]);
		strlcat(buffer, "/", ft_strlen(paths[i]) + ft_strlen("/") + 1);
		strlcat(buffer, names[0], ft_strlen(buffer) + ft_strlen(names[0]) + 1);
		printf("buffer: %s\n", buffer);
		ret = execve(buffer, names, NULL);
		printf("ret: %d\n", ret);
		free(buffer);
		i++;
	}
	free (paths);
}
