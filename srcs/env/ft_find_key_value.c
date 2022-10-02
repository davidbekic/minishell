/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:39:10 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/22 11:54:28 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_find_key(char *pattern)
{
	int		i;

	i = 0;
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
	while (pattern[i] != '=' && pattern[i] != 0)
		i++;
	// IF THERE IS NO VALUE, JUST RETURN SIZE OF KEY ANYWAY
	if (pattern[i] == 0)
		return (0);
	// IF THERE IS EQUALS SIGN, BUT NO VALUE
	else if (pattern[i] == '=' && pattern[i + 1] == 0)
		return (0);
	i++;
	return (i);
}	
