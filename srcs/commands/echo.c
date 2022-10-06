/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 13:37:40 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(t_env *env, char **names)
{
	unsigned char 	n_flag;
	char			**start_ptr;
	unsigned char	home_flag;
	n_flag = 0;

	start_ptr = (char **) names;
	while (*names != NULL)
	{
		if (strcmp(*(names), "-n") == 0)
			n_flag++;
		names++;
	}
	names = start_ptr;
	while (*(names + 1 + n_flag))
	{
		home_flag = 0;
		if (!(ft_strncmp(*(names + 1 + n_flag), "~", ft_strlen(*(names + 1 + n_flag))))
			|| (names[1 + n_flag][0] == '~' && (names[1 + n_flag][1] == '/')))
		{
			home_flag++;
			printf("%s", ft_expand(env, "HOME"));
		}
		printf("%s", *(names + 1 + n_flag) + home_flag);
		if (*(names + 2 + n_flag) != NULL)
			printf(" ");
		names++;
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

