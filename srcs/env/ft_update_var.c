/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:34:48 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/08 20:12:11 by dbekic           ###   ########.fr       */
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
	if (!elem)
	{
		while (list->next != NULL)
			list = list->next;
		//elem = ft_create_elem(elem, value);
		elem = ft_create_elem(elem, key, value);
		list->next = elem;
	}
	else
	{
		while (value[i] != 0)
		{
			elem->value[i] = value[i];
			i++;
		}
	//            free(key);
	//            free(value);
		elem->value[i] = 0;
	}
}
