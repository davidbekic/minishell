/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/19 17:56:41 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_find_elem_before(t_env *env_list, char *key)
{
	t_env	*aux;

	aux = env_list;
	while (aux != NULL)
	{
		printf("up in this bish?\n");
		if (strncmp(aux->key, key, ft_find_value(key)) == 0)
			return (NULL);
		if (strncmp(aux->next->key, key, ft_find_value(key)) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_env	*ft_find_elem(t_env *env_list, char *key)
{
	t_env	*aux;

	aux = env_list;
	while (aux != NULL)
	{
		if (strncmp(aux->key, key, ft_find_value(key) - 1) == 0)
			return (aux);
	aux = aux->next;
	}
	return (NULL);
}
