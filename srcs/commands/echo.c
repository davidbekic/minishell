/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/08 19:18:51 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	ft_check_n_flag(char **names)
{
	unsigned char	n_flag;
	int				no_flag;
	char			**head;

	n_flag = 0;
	no_flag = 1;
	head = names;
	while (*names++)
	{
		if ((!(ft_strncmp(*names, "-n", 2))))
		{
			while (*(*names))
			{
				printf("*(*names + 1): %c\n", *(*names + 1));
				if (*(++*names) != 'n' && *(*names) != 0)
					return (n_flag);
			}
			if (no_flag)
				n_flag++;
		}
	}
	printf("n_flag: %d\n", n_flag);
	return (n_flag);
}

static int	ft_is_home(char *names)
{	
	unsigned char	home_flag;
	
	home_flag = 0;
	if (!(ft_strncmp(names, "~", ft_strlen(names)))
		|| (names[0] == '~' && names[1] == '/'))
	{
		printf("names[0]: %d\n", names[0]);
		home_flag++;
	}
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
		home_flag = 0;
		if (home_flag)
			printf("%s", ft_expand(env, "HOME"));
		printf("%s", *(names + n_flag) + home_flag);
		if (*(names + 1 + n_flag) != NULL) // if not last item
			printf(" ");
	}
	// printf("n_flag: %d\n", n_flag);
	if (!n_flag)
		printf("\n");
}
