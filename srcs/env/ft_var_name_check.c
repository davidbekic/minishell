/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_name_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:57:51 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/13 18:31:55 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_var_name_check(char *str, int len)
{
	int		i;
	char	buf[200];

	i = 0;
	if (len < 1)   // not sure why this exists, maybe some NULL case?
		return (1);
	ft_memcpy(buf, str, len); // putting only var_NAME in buf
	buf[len] = 0; // NULL-terminating manually, otherwise we would copy one char too much
	while (str[i] != 0 && i < len)
	{
		if (str[i] >= '0' && str[i] <= '9' && i == 0)
			return (1);
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i]
				<= 'Z') && str[i] != '_' && !(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
