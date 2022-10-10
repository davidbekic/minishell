/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:39:37 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/10 16:35:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_envsize(t_env *env)
{
	t_env	*ptr;
	int		counter;

	counter = 0;
	ptr = env;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}

void    ft_alphabetic_env(t_env *env)
{
	int     i;
	int     j;
	int		lst_size;
	t_env	*aux;
	t_env	*temp;

	i = 0;
	j = 0;
	lst_size = ft_envsize(env);
	aux = env;
	temp = aux;
	while (j < lst_size - 1)
	{
		while (aux != NULL)
		{
			if (ft_strncmp(temp->key, aux->key, 50) < 0)
				i++;
			aux = aux->next;
		}
		if (i == lst_size - j - 2)
		{
			if (strncmp(temp->key, "_", 3) != 0)
			{
				printf("declare -x %s", temp->key);
				if (temp->value)
					printf("=\"%s\"", temp->value);
				printf("\n");	
			}
			aux = env;
			temp = env;
			j++;
			i = 0;
			continue ;
		}
		temp = temp->next;
		aux = env;
		i = 0;
	}
}

void    ft_env(t_env *env, char **names)
{
    int     i;
    t_env   *aux;

	if (*(names + 1))
	{
		printf("env: %s: no such file or directory\n", *(names + 1));
		return ;
	}
    i = 0;
    aux = env;
    while (aux != NULL)
    {
		if (aux->value != NULL)
        	printf("%s=%s\n", aux->key, aux->value);
        aux = aux->next;
        i++;
    }
	//ft_free_env(env_list);
}
