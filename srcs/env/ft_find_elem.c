/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/04 13:11:22 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static int ft_strlen_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] > 31)
		i++;
	return (i);
}

t_env	*ft_find_elem_before(t_env *env_list, char *key)
{
	t_env	*aux;

	aux = env_list;
	// ITERATING THROUGH ENV LIST
	while (aux != NULL)
	{
		if (strncmp(aux->key, key, ft_strlen(key)) == 0)
			return (NULL);
		if (strncmp(aux->next->key, key, ft_strlen(key)) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_env	*ft_find_elem(t_env *env_list, char *key)
{
	t_env	*aux;

	aux = env_list;
	// ITERATING THROUGH ENV LIST
	while (aux != NULL)
 	{
		if (ft_strncmp(aux->key, key, 4096) == 0)
			return (aux);
//		printf("aux->key: %s\n", aux->key);
		aux = aux->next;
		//printf("aux->next: %s\n", aux->next->key);
	}
	return (NULL);
}
