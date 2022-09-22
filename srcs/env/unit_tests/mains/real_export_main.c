#include "../../../../includes/minishell.h"

int main(int ac, char **av, char **env)
	{
	t_env	*env_list;
	t_env	*aux;
	int	i = 0;
	char	new_str_to_export[30][30];

	if (ac == 0 || av == NULL)
		exit(0);
	env_list = NULL;
	env_list = ft_init_env(env);


	memcpy(new_str_to_export[0], "USER=\" foo   bar\"", 25);
	memcpy(new_str_to_export[1], "hello=\"\"\"\"\" foo   bar \"\"\"\"\"", 25);
	memcpy(new_str_to_export[2], "hello= foo   bar ", 25);
	memcpy(new_str_to_export[3], "=haha", 5);
	printf("hello?\n");
	while (i < 4)
	{
		printf("TESTING: 'export %s'\n", new_str_to_export[i]);
		ft_export(new_str_to_export[i], env_list);
		i++;
	}

	printf("TESTING: 'export'\n");
	ft_export(NULL, env_list);
//	ft_echo(&"hello $HOME", env);
	//ft_export(existing_str_to_export, env_list);
	ft_env(env_list);
	free_env(env_list);


	//ft_init_env(env);
	}
