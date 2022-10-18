/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:35 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/13 18:37:06 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char **names)
{
	unsigned char	ret;

	ret = 0;
	printf("exit\n");
	if (names[2])
	{
		printf("minishell: exit: too many arguments\n");
		ret = 1;
	}
	else if (names[1]) // NEED TO CHECK IF NUMERIC OR NOT AS WELL
		ret = (unsigned char) ft_atoi(names[1]);
	exit (ret);
}
