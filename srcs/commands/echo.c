/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/11 16:12:06 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	ft_check_n_flag(char **names)
{
	unsigned char	n_flag;
	int				no_flag;
	int				i;
	int				j;

	n_flag = 0;
	no_flag = 1;
	i = 0;
	j = 1;
	while (names[i])
	{
		if ((!(ft_strncmp(names[i], "-n", 2))))
		{
			while (names[i][j])
			{
				if (names[i][j] != 'n' && (names[i][j + 1] != 0 || names[i][j + 1] != 32))
					return (n_flag);
				j++;
			}
			if (no_flag)
				n_flag++;
		}
		i++;
		j = 1;
	}
	return (n_flag);
}

void	ft_echo(char **names)
{
	unsigned char 	n_flag;

	n_flag = 0;
	n_flag = ft_check_n_flag(names);
	while (*(++names + n_flag))
	{
		printf("%s", *(names + n_flag));
		if (*(names + 1 + n_flag) != NULL && ft_strlen(*(names + n_flag)))
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
}
