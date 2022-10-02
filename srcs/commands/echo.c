/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:58:05 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/21 13:25:38 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **names)
{
	unsigned char 	n_flag;
	char			**start_ptr;
	n_flag = 0;

	start_ptr = (char **) names;
	if (!names[1])
	{
		printf("\n");
		return ;
	}
	while (*names != NULL)
	{
		printf("names: %s\n", *names);
		if (strncmp(*(names), "-n", 2) == 0)
			n_flag++;
		names++;
	// else if (strncmp(names[1], "-n", 2) == 0)
	// {
	// 	names++;
	// 	n_flag = 1;
	// }
	}
	printf("n_flag: %d\n", n_flag);
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

