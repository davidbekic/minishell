/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 18:17:15 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int	g_exit;

int	main(int ac, char **av, char **main_env)
{
	static char		*buf;
	t_env			*env;

	if ((ac > 1 && av[0][0] == '&') || !*main_env)
		exit(1);
	env = ft_init_env(main_env);
	buf = (char *)ft_calloc(sizeof(char) * BUFFER_SIZE, 1);
	if (!buf | !env)
		ft_free_env(env, 1);
	ft_main_loop(&buf, &env);
	return (0);
}






	// if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	// {
	// 	ft_memset(buf, 0, ft_strlen(buf) + 1);
	// 	ft_memcpy(buf, av[2], ft_strlen(av[2]) + 1);
	// 	ft_prompt_parser(&buf, env);
	// 	ft_runcmd(ft_parsecmd(buf), env);
	// 	exit(0);
	// }