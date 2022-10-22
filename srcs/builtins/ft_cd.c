/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:09:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/22 16:18:24 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(t_env *env, char **names)
{
	char	old_pwd[BUFFER_SIZE];
	char	new_pwd[BUFFER_SIZE];
	char	s[BUFFER_SIZE];
	int		ret;

	if (names[1] && ft_is_file(names[1]))
	{
		ft_printf(2, "minishell: cd: %s: Not a directory\n", names[1]);
		return (1);
	}
	bzero(old_pwd, BUFFER_SIZE);
	bzero(new_pwd, BUFFER_SIZE);
	ft_memcpy(new_pwd, "PWD=", 5);
	ft_memcpy(old_pwd, "OLDPWD=", 8);
	ft_memcpy(old_pwd + 7, getcwd(s, BUFFER_SIZE),
		ft_strlen(getcwd(s, BUFFER_SIZE)) + 1);
	if ((!(ft_strncmp(*(names + 1), "--", ft_strlen(*(names + 1))))))
	{
		ret = chdir((ft_expand(env, "OLDPWD")));
		printf("%s\n", getcwd(s, BUFFER_SIZE));
	}
	else if (!(*(names + 1)))
	{
		if (!ft_expand(env, "HOME"))
			ret = ft_printf(2, "minishell: cd: HOME not set\n");
		else
			ret = chdir(ft_expand(env, "HOME"));
	}
	else
		ret = chdir (*(names + 1));
	if (ret == -1)
		ft_printf(2, "minishell: cd: %s: No such file or directory\n",
			*(names + 1));
	ft_memcpy(new_pwd + 4, getcwd(s, BUFFER_SIZE),
		ft_strlen(getcwd(s, BUFFER_SIZE)) + 1);
	ft_update_var(new_pwd, 4, env);
	ft_update_var(old_pwd, 7, env);
	return (ret * -1);
}
