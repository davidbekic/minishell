/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:09:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/07 18:55:30 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_cd(t_env *env, char **names)
{
    char *env_var;

    env_var = NULL;
    if (!(ft_strncmp(*(names + 1), "-", ft_strlen(*(names + 1)))))
    {
        chdir(*(names + 1));
        ft_memcpy(env_var, "OLDPWD", 100);
        printf("*(names + 1): %s\n", *(names + 1));
        ft_export(&env_var, env);
        printf("%s\n", ft_expand(env, "OLDPWD"));
        return (0);
    }
    return (0);
}