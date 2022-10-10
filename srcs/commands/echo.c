/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/10 18:15:24 by dbekic           ###   ########.fr       */
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
		printf("strncmp(names[i], -n, 2): %d\n", ft_strncmp(names[i], "-n", 2));
		if ((!(ft_strncmp(names[i], "-n", 2))))
		{
			while (names[i][j])
			{
				printf("names[%d][%d]: %c\n", i, j, names[i][j]);
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

static int	ft_is_home(char *names)
{	
	unsigned char	home_flag;
	
	home_flag = 0;
	if ((names[0] == '~' && names[1] == 32) ||
		(names[0] == '~' && names[1] == 0) ||
		(names[0] == '~' && names[1] == '/'))
		home_flag++;
	return (home_flag);
}

void	ft_echo(t_env *env, char **names)
{
	unsigned char 	n_flag;
	unsigned char	home_flag;

	n_flag = 0;
	printf("*(names + n_flag==1): %s\n", *(names + n_flag + 1));
	printf("n_flag: %d\n", n_flag);
	n_flag = ft_check_n_flag(names);
	printf("n_flag: %d\n", n_flag);
	printf("*(names + n_flag): %s\n", *(names + n_flag + 1));
	while (*(++names + n_flag))
	{
		home_flag = ft_is_home(*(names + n_flag));
		if (home_flag)
			printf("%s", ft_expand(env, "HOME"));
		printf("%s", *(names + n_flag) + home_flag);
		if (*(names + 1 + n_flag) != NULL && ft_strlen(*(names + n_flag)))   // if not last item or empty str
			printf(" ");
	}
	// printf("n_flag: %d\n", n_flag);
	if (!n_flag)
		printf("\n");
}
