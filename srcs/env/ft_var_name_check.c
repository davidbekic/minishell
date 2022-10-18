/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_name_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:57:51 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/18 22:43:14 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_var_name_check(char *str, int len)
{
	int		i;
	char	buf[BUFFER_SIZE];

	i = 0;
	if (len < 1)
		return (1);
	ft_memcpy(buf, str, len);
	buf[len] = 0;
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
