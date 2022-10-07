/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/07 12:52:57 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	ft_check_n_flag(char **names)
{
	unsigned char	n_flag;

	// need to check for "echo -nndfighdsl word" case.
	// that should not be valid -n flag.
	n_flag = 0;
	while (ft_strncmp(*(++names), "-n", 2) == 0)
		n_flag++;
	return (n_flag);
}

static int	ft_is_home(char *names)
{	
	unsigned char	home_flag;

	home_flag = 0;
	if (!(ft_strncmp(names, "~", ft_strlen(names)))
		|| (names[0] == '~' && names[1] == '/'))
		home_flag++;
	return (home_flag);
}

void	ft_echo(t_env *env, char **names)
{
	unsigned char 	n_flag;
	unsigned char	home_flag;

	n_flag = ft_check_n_flag(names);
	while (*(++names + n_flag))
	{
		home_flag = ft_is_home(*(names + n_flag));
		if (home_flag)
			printf("%s", ft_expand(env, "HOME"));
		printf("%s", *(names + n_flag) + home_flag);
		if (*(names + 1 + n_flag) != NULL) // if not last item
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
}
