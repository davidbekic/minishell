/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:04:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/05 14:15:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write(2, "(null)", 6));
	return (write(2, str, ft_strlen(str)));
}
