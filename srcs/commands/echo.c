/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 18:45:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	ft_check_n_flag(char **names)
{
	unsigned char	n_flag;

	n_flag = 0;
	while (ft_strncmp(*(++names), "-n", 2) == 0)
		n_flag++;
	return (n_flag);
}

static int	is_home(char *names)
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
		home_flag = is_home(*(names + n_flag));
		if (home_flag)
			printf("%s", ft_expand(env, "HOME"));
		printf("%s", *(names + n_flag) + home_flag);
		if (*(names + 1 + n_flag) != NULL) // if not last item
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
}

// int	main(void)
// {
// 	char	**names;
// 	int		i = 1;

// 	names = malloc(200000);
// 	names[0] = malloc(200);
// 	names[0] = "echo";
// 	names[1] = malloc(200);
// 	names[1] = "hello";
// 	names[2] = malloc(200);
// 	names[2] = NULL;
// 	names[3] = malloc(200);
// 	names[3] = NULL;
// 	names[4] = NULL;
// 	// {
// 	// 	names[i] = malloc(20);
// 	// 	names[i] = "he\n";
// 	// 	i++;
// 	// }
// 	// names[i] = NULL;

// 	// names[1] = "hello";
// 	// names[2] = "there";
// 	// names[3] = NULL;
// 	ft_echo(names);

// }

