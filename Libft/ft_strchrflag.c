/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:41:52 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 12:14:59 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrflag(const char *str, int ch, int flag)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch && flag == 0)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch && flag == 0)
		return ((char *)str + position);
	return (0);
}