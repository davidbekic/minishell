/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:08:29 by davidbekic        #+#    #+#             */
/*   Updated: 2022/10/18 22:34:29 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void ft_command_to_lower(char *command)
{
    while (*command++)
        *(command - 1) = ft_tolower(*(command - 1));
}

int ft_find_command(struct doexec *execcmd, t_env *env)
{
    int ret;

    ret = 0;
    ft_command_to_lower(execcmd->names[0]);
    if (!(ft_strcmp(execcmd->names[0], "env")))
        ret = ft_env(env, execcmd->names);
    else if (!(ft_strcmp(execcmd->names[0], "echo")))
        ret = ft_echo(execcmd->names);
    else if (!(ft_strcmp(execcmd->names[0], "export")))
        ret = ft_export(execcmd->names, env);
    else if (!(ft_strcmp(execcmd->names[0], "exit")))
        ft_exit(execcmd->names);
    else if (!(ft_strcmp(execcmd->names[0], "unset")))
        ret = ft_unset(execcmd->names, &env);
    else if (!(ft_strcmp(execcmd->names[0], "cd")))
        ret = ft_cd(env, execcmd->names);
    else if (!(ft_strcmp(execcmd->names[0], "pwd")))
        ret = ft_pwd(env);
    else
        ret = ft_execve(env, execcmd->names);
    return (ret);
}