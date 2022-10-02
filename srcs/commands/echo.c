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
	unsigned char n_flag;
	n_flag = 0;

	if (!names[1])
	{
		printf("\n");
		return ;
	}
	else if (strncmp(names[1], "-n", 2) == 0)
	{
		names++;
		n_flag = 1;
	}
	while (*++names)
	{
		printf("%s", *names);
		if (*(names + 1) != NULL)
			printf(" ");
	}
	if (!n_flag)
		printf("\n");
}

// int	main(void)
// {
// 	char **names;
// 	int		i = 1;

// 	names = malloc(200000);
// 	names[0] = malloc(20000);
// 	names[0] = "echo";
// 	while (i < 10000)
// 	{
// 		names[i] = malloc(20);
// 		names[i] = "he\n";
// 		i++;
// 	}
// 	names[i] = NULL;
// 	// names[1] = "hello";
// 	// names[2] = "there";
// 	// names[3] = NULL;
// 	ft_echo(names);

// }

