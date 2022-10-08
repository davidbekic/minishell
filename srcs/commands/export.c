/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:32:49 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/07 17:17:51 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_update_var(char *key_value, int value_start, t_env *env)
{
	t_env	*elem;
	t_env	*aux;
	int		i;
	int		j;
	char	key[100];

	i = 0;
	j = 0;
	aux = env;
	strncpy(key, key_value, value_start - 1);
	elem = ft_find_elem(env, key);
	if (!elem) // CREATING ELEMENT
	{
		while (strcmp(env->next->key, "_") != 0)
			env = env->next;
		//elem = ft_create_elem(elem, key_value, ft_find_value(key_value));
		elem = ft_create_elem(elem, key_value, value_start);
		aux = env->next;
		env->next = elem;
		elem->next = aux;
	}
	else // UPDATE VARIABLE
	{
		while (key_value[value_start + i] != 0)
		{
			i++;
			if (key_value[value_start + i - 1] != '\'' && key_value[value_start + i - 1] != '\"' )
				elem->value[++j - 1] = key_value[value_start + i - 1];
		}
		elem->value[i] = 0;
	}
	//free(env->envp);
	// ft_free_envp(env->envp);
	// env->envp = ft_create_envp(env);
}

int	ft_export(char **names, t_env *env)
{
	short	ret;

	ret = 0;
	printf("names[1] in EXPORT: %s\n", names[1]);
	if (!names[1])
		ft_alphabetic_env(env);
	while (*++names)
	{
		ret = ft_var_name_check(*names, ft_find_value(*(names)) - 1);
		if (ret)
			printf("minishell: export: `%s': not a valid identifier\n", *names);
		else if (!ret)
			ft_update_var(*names, ft_find_value(*names), env);			
	}		
	return (ret);
}

// int	main(int ac, char **av, char **main_env)
// {
// 	int	i;
// 	t_env	*env;
// 	char **nullstr;

// 	nullstr = malloc(200);
// 	nullstr[0] = malloc(200);
// 	nullstr[1] = malloc(200);
// 	nullstr[0] = "./a.out";
// 	nullstr[1] = NULL;

	
// 	i = 0;
// 	env = ft_init_env(main_env);
// 	ft_export(av, env);
// 	ft_export(nullstr, env);
// 	ft_env(env);
// 	ft_free_env(env);
// }
