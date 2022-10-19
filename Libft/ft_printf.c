/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:12:12 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 12:18:35 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int ft_putstring(int fd, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (str[i] != 0)
		i++;
	write(fd, str, i);
	return (i);
}

static int ft_put_number(int fd, int nb)
{
	int rem;
	static int i;
	int j;

	i = 0;
	j = 0;
	if (nb == INT_MIN)
		return (write(fd, "-2147483648", 11));
	if (nb < 0)
	{
		nb *= -1;
		j++;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		rem = nb % 10;
		ft_put_number(fd, nb/10);
	}
	rem = nb % 10;
	rem += 48;
	i++;
	write (fd, &rem, 1);
	return (i + j);
}

static int ft_argcheck(int fd, va_list arg, char c)
{
	int	i;

	i = 0;
	if (c == 's')
		i = ft_putstring(fd, va_arg(arg, char *));
	if (c == 'd')
		i = ft_put_number(fd, va_arg(arg, int));
	return (i);
}

int ft_printf(int fd, const char *format, ...)
{
	int	i;
	int	j;
	va_list arg;

	i = 0;
	j = 0;
	va_start(arg, format);
	while (format[i] != 0)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j += ft_argcheck(fd, arg, format[i + 1]);
			i += 2;
			continue ;
		}
		write(fd, &format[i], 1);
		i++;
		j++;
	}
	return (j);
}
