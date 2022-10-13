/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:16 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 16:55:01 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// static int	ft_len(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	while (n)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int n)
// {
// 	char		*ptr;
// 	int			len;
// 	long int	nbr;

// 	len = ft_len(n);
// 	nbr = n;
// 	if (n < 0)
// 	{
// 		nbr = nbr * (-1);
// 		len = len + 1;
// 	}
// 	ptr = malloc(sizeof(char) * (len) + 1);
// 	if (!(ptr))
// 		return (NULL);
// 	if (n == 0)
// 		*ptr = 0 + 48;
// 	ptr[len] = '\0';
// 	while (len--)
// 	{	
// 		ptr[len] = (nbr % 10) + 48;
// 		nbr /= 10;
// 	}
// 	if (n < 0)
// 		*ptr = '-';
// 	return (ptr);
// }

char	*ft_itoa(int n)
{
	static int i;
	static char str[4096];

	ft_bzero(str, 4096);
	i = 0;
	if (n > 9)
	{
		ft_itoa(n / 10);
		i++;
	}
	else
		i++;
	str[i - 1] = (n % 10) + 48;
	str[i] = 0;
	return (str);
}