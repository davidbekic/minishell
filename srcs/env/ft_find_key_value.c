/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:39:10 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/05 16:38:21 by dbekic           ###   ########.fr       */
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
	if (pattern[i] == 0)	// IF THERE IS NO VALUE, JUST RETURN SIZE OF KEY ANYWAY
		return (i + 1);
	else if (pattern[i] == '=' && pattern[i + 1] == 0)	// IF THERE IS EQUALS SIGN, BUT NO VALUE
		return (i + 1);
	i++;
	return (i);
}	
