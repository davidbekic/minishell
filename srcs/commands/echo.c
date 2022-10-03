/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/03 13:49:29 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **names)
{
	unsigned char 	n_flag;
	char			**start_ptr;
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
		printf("%s", *(names + 1 + n_flag));
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

