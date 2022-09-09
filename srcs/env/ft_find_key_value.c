/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:39:10 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/09 12:45:47 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_key(char *pattern)
{
	int		i;
	char	*key = NULL;

	i = 0;
	while (pattern[i] != 0 && pattern[i] != '=')
	i++;
	key = calloc(10000, 1);
	if (!key)
		return (NULL);
	i = 0;
	while (pattern[i] != '=' && pattern[i] != 0)
	{
		key[i] = pattern[i];
		i++;
	}
	return (key);
}

char	*ft_find_value(char *pattern)
{
	int		i;
	int		j;
	char	*value = NULL;

	i = 0;
	j = 0;
	while (pattern[i] != '=')
		i++;
	i++;
	value = calloc(strlen(pattern) - i + 1, 1);
	if (!value)
		return (NULL);
	while (pattern[i] != 0)
		value[j++] = pattern[i++];
	return (value);
}	
