/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:39:37 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/15 13:23:22 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_envsize(t_env *lst)
{
	t_env	*ptr;
	int		counter;

	counter = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}

void    ft_alphabetic_env(t_env *env_list)
{
	int     i;
	int     j;
	int		lst_size;
	t_env	*aux;
	t_env	*temp;

	i = 0;
	j = 0;
	lst_size = ft_envsize(env_list);
	aux = env_list;
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
				printf("declare -x %s=%s\n", temp->key, temp->value);
			aux = env_list;
			temp = env_list;
			j++;
			i = 0;
			continue ;
		}
		temp = temp->next;
		aux = env_list;
		i = 0;
	}
}

void    ft_env(t_env *env_list)
{
    int     i;
    t_env   *aux;

    i = 0;
    aux = env_list;
    while (aux != NULL)
    {
        
        printf("%s=%s\n", aux->key, aux->value);
        aux = aux->next;
        i++;
    }
}
