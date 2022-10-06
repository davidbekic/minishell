/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:15:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 16:32:03 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_create_elem(t_env *new, char *key_value, int value_start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	if (value_start == 0)
		return (NULL);
	new = (t_env *) ft_calloc(1, sizeof(t_env));
	if (!new)
			return (NULL);
	new->key = (char *) ft_calloc(value_start, 1);
	if (!new->key)
		return (NULL);
	new->value = (char *) ft_calloc(strlen(key_value) + 100 - value_start, 1);
	if (!new->value)
		return (NULL);
	while (++i < value_start)
		new->key[i - 1] = key_value[i - 1];
	i = 0;
	while (*(key_value + value_start + i) != 0)
	{
		new->value[j] = key_value[value_start + i];
		j++;
		i++;
	}
	new->value[j] = 0;
	if (key_value[value_start - 1] == 0)
		new->value = NULL;
	new->next = NULL;
	return (new);
}
