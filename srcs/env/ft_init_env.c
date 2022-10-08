/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:20 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/08 18:15:38 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_create_envp(t_env *env)
{
	t_env	*ptr;
	char	**head;

	ptr = env;
	
	env->envp = (char **) malloc(sizeof(char*) * ft_envsize(env));
	head = env->envp;
	while (ptr)
	{
		*env->envp = malloc(ft_strlen(ptr->key) + ft_strlen("=") + ft_strlen(ptr->value) + 1);
		ft_memcpy(*env->envp, ptr->key, ft_strlen(ptr->key) + 1);
		ft_memcpy(*env->envp + ft_strlen(ptr->key), "=", 2);
		ft_memcpy(*env->envp + ft_strlen(ptr->key) + 1, ptr->value, ft_strlen(ptr->value) + 1);
		env->envp++;
		ptr = ptr->next;
	}
	*env->envp = NULL;
	return (env->envp - (env->envp - head));
}

t_env	*ft_init_env(char **main_env)
{
	t_env	*head;
	t_env	*current;
	t_env	*temp;
	int		i;

	head = NULL;
	head = ft_create_elem(head, main_env[0], ft_find_value(main_env[0]));
	if (!head)
	{
		ft_free_env(head);
		return (NULL);
	}
	temp = head;
	i = 1;
	while (main_env[i] != NULL)
	{
		current = ft_create_elem(current, main_env[i], ft_find_value(main_env[i]));
		if (!current)
		{
			ft_free_env(head);
			return (NULL);
		}
		temp->next = current;
		temp = current;
		i++;
	}
	head->envp = ft_create_envp(head);
	return (head);
}
