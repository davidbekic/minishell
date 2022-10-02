/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_name_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:57:51 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/22 13:58:04 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_non_allowed_char_for_var_name(char *str, int len)
{
	int	i;
	char	buf[100];

	i = 0;
	ft_memcpy(buf, str, len); // putting only var_NAME in buf
	buf[len] = 0; // memcpy not NULL-terminating fro some reason.
	while (str[i] != 0 && i < len)
	{
		if (str[i] >= '0' && str[i] <= '9' && i == 0)
			return (1);
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')
			&& str[i] != '_' && !(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
