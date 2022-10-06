/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 16:52:13 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_find_elem_before(t_env *env, char *key)
{
	t_env	*aux;

	aux = env;
	while (aux != NULL)		// ITERATING THROUGH ENV LIST
	{
		if (strncmp(aux->key, key, ft_strlen(key)) == 0)
			return (NULL);
		if (strncmp(aux->next->key, key, ft_strlen(key)) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_env	*ft_find_elem(t_env *env, char *key)
{
	t_env	*aux;

	aux = env;
	while (aux != NULL)   	// ITERATING THROUGH ENV LIST
 	{
		if (ft_strncmp(aux->key, key, 4096) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}
