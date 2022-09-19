/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:39:10 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/19 17:33:56 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_find_key(char *pattern)
{
	int		i;

	if (!pattern)
		return (0);
	while (pattern[i] != 0 && pattern[i] != '=')
		i++;
	return (i);
}

int	ft_find_value(char *pattern)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!pattern)
		return (0);
	while (pattern[i] != '=')
		i++;
	i++;
	return (i);
}	
