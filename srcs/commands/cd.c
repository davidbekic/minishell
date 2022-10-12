/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:09:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/12 17:53:54 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_cd(t_env *env, char **names)
{
    char old_pwd[200];
    char new_pwd[200];
    char    s[100];
    int     ret;

    bzero(old_pwd, 200);
    bzero(new_pwd, 200);
    ft_memcpy(new_pwd, "PWD=", 4);
    ft_memcpy(old_pwd, "OLDPWD=", 7);
    ft_memcpy(old_pwd + 7, getcwd(s, 100), ft_strlen(getcwd(s, 100)));
    if ((!(ft_strncmp(*(names + 1), "--", ft_strlen(*(names + 1))))))
        ret = chdir((ft_expand(env, "OLDPWD")));
    else if (!(*(names + 1)))
        ret = chdir(ft_expand(env, "HOME"));
    else
        ret = chdir (*(names + 1));
    if (ret == -1)
        printf("minishell: cd: %s: No such file or directory\n", *(names + 1));
    ft_memcpy(new_pwd + 4, getcwd(s, 100), ft_strlen(getcwd(s, 100)));
    ft_update_var(new_pwd, 4, env);
    ft_update_var(old_pwd, 7, env);
    return (ret * -1);
}
