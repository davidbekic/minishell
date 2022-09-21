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

static int	ft_is_even(char **names)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (names[j] != NULL)
	{
		while (names[j][i] != 0)
		{
			if ()
			i++; 
		}
		printf("\n");
		i = 0;
		j++;
	}
	return (1);
}

void	ft_echo(char **names)
{
	unsigned char n_flag;

	ft_is_even(names);
	n_flag = 0;
//	if (strncmp(names[1], "-n", 2) == 0)
//	{
//		names++;
//		n_flag++;
//	}
//	while (*++(*names) != 0)
//		printf("%c", **names);

//	while (*names++)
//		printf("%s\n", *names + n_flag);
	if (!n_flag)
		printf("\n");
}

int	main(void)
{
	char **names;

	names = malloc(2000);
	names[0] = malloc(2000);
	names[1] = malloc(2000);
	names[2] = malloc(2000);
	names[0] = "echo";
	names[1] = "-n";
	names[2] = "hello";
	names[3] = "there";
	names[4] = NULL;
	ft_echo(names);

}

