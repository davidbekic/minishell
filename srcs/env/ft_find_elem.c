/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/22 20:41:58 by dbekic           ###   ########.fr       */
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
	printf("key in ft_find_elem_before: %s\n", key);
	return (NULL);
}

t_env	*ft_find_elem(t_env *env_list, char *key)
{
	t_env	*aux;

	aux = env_list;
	
	
	printf("entering find_elem with key[4]: %c\n", key[4]);
	printf("strlen(key): %d\n", ft_strlen_printable(key));
	// ITERATING THROUGH ENV LIST
	while (aux != NULL)
	{
	//	printf("strncmp(%s, %s, %d): %d\n", aux->key, key, ft_strlen_printable(key), strncmp(aux->key, key, ft_strlen_printable(key)));
		if (strncmp(aux->key, key, ft_strlen_printable(key)) == 0)
		{
			printf("found %s\n", aux->key);
			return (aux);
		}
		aux = aux->next;
	}
	return (NULL);
}
