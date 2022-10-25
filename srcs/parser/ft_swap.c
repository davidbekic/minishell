/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/24 19:02:43 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_swap(void *dest, void *src, size_t count)
{
	char	tmp;
	char	*ptr;
	char	*ptr_src;

	ptr = (char *)dest;
	ptr_src = (char *)src;
	tmp = *ptr;
	while (count--)
	{
		*ptr = *ptr_src;
		*ptr_src = tmp;
	}
	return (dest);
}
