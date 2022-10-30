/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:35 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/30 02:53:18 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static int	ft_num_arg(char *str)
{
	int	i;

	i = -1;
	// while (i++ < (int) ft_strlen(str))
	while (str[++i] != 0)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue ;
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

void	ft_exit(t_doexec *execcmd)
{
	unsigned char	ret;

	ret = 0;
	// ft_printf(1, "exit\n");
	if (execcmd->names[2] && !ft_num_arg(execcmd->names[1]))
	{
		ft_printf(2, "minishell: exit: too many arguments\n");
		ret = 1;
	}
	else if (execcmd->names[1])
	{
		if (ft_num_arg(execcmd->names[1]) || (!ft_atoi(execcmd->names[1])
				&& ft_strlen(execcmd->names[1]) > 9))
		{
			ft_printf(2, "minishell: exit: %s: numeric argument required\n",
				execcmd->names[1]);
			ret = -1;
		}
		else
			ret = (unsigned char) ft_atoi(execcmd->names[1]);
	}
	free(execcmd->names[0]);
	free(execcmd);
	exit (ret);
}
