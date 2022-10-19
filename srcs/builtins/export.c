/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:32:49 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 13:26:32 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static int	ft_update_existing_var(char *key_value, int value_start, t_env *elem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!elem->value)
	{
		elem->value = malloc((ft_strlen(key_value) - value_start) + 1);
		if (!elem->value)
			return (1);
	}
	while (key_value[value_start + i] != 0)
	{
		i++;
		if (key_value[value_start + i - 1] != '\''
			&& key_value[value_start + i - 1] != '\"' )
			elem->value[++j - 1] = key_value[value_start + i - 1];
	}
	elem->value[i] = 0;
	return (0);
}

int	ft_update_var(char *key_value, int value_start, t_env *env)
{
	t_env	*elem;
	t_env	*aux;
	char	key[BUFFER_SIZE];
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = env;
	ft_bzero(key, BUFFER_SIZE);
	ft_memcpy(key, key_value, value_start - 1);
	key[ft_strlen(key)] = 0;
	elem = ft_find_elem(env, key);
	if (!elem) 
	{
		while (ft_strcmp(env->next->key, "_") != 0)
			env = env->next;
		elem = ft_create_elem(elem, key_value, value_start);	
		aux = env->next;
		env->next = elem;
		elem->next = aux;
	}
	else
	{
		if (ft_update_existing_var(key_value, value_start, elem))
			return (1);
	}
	return (0);
}

int	ft_export(char **names, t_env *env)
{
	short	ret;

	ret = 0;
	if (!names[1])
		ft_alphabetic_env(env);
	while (*++names)
	{
		if (ft_strlen(*names) > BUFFER_SIZE)
		{
			ft_printf(2, "too long variable name or value\n");
			return 1;
		}
		ret = ft_var_name_check(*names, ft_find_value(*(names)) - 1);
		if (ret)
		{
			ret = 1;
			printf("minishell: export: `%s': not a valid identifier\n", *names);
		}
		else if (!ret)
			ret = ft_update_var(*names, ft_find_value(*names), env);
	}
	return (ret);
}