/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:34:48 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/19 14:26:08 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_var(char *key, char *value, t_env *list)
{
	t_env	*elem;
	t_env	*aux;
	int		i;

	i = 0;
	aux = list;
	elem = ft_find_elem(list, key);
	// CREATING ELEMENT
	if (!elem)
	{
		while (strcmp(list->next->key, "_") != 0)
			list = list->next;
		elem = ft_create_elem(elem, key, value);
		aux = list->next;
		list->next = elem;
		elem->next = aux;
	}
	// UPDATE VARIABLE
	else
	{
		while (value[i++] != 0)
			elem->value[i - 1] = value[i - 1];
		elem->value[i - 1] = 0;
		free(key);
		free(value);
	}
}
