/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 17:35:41 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_unset(char *key, t_env *env)
{
    t_env   *to_delete;
    t_env   *to_redirect;
    
    if (!key)
        return (0);
    if (strcmp(key, "_") == 0)  // IF TRYING TO CHANGE LAST ENV VARIABLEE
        return (0);
    to_delete = ft_find_elem(env, key);
    if (!to_delete)
        return (0);
    to_redirect = ft_find_elem_before(env, key);
    if (!to_redirect)
        return (0);
    if (!to_redirect)
        env = to_delete->next;
    else
        to_redirect->next = to_delete->next;
    free(to_delete->key);
    free(to_delete->value);
    free(to_delete);
    ft_free_envp(env->envp);
    printf("envp head address: %p\n", env->envp);
    //free(env->envp);
    env->envp = ft_create_envp(env);
    return (0);
}

// int main(int ac, char **av, char **main_env)
// {
//     int i;
//     t_env *env;
//     char **nullstr;

// 	nullstr = malloc(200);
// 	nullstr[0] = malloc(200);
// 	nullstr[1] = malloc(200);
// 	nullstr[0] = "./a.out";
// 	nullstr[1] = NULL;

//     i = 0;
//     env = ft_init_env(main_env);
    
//     ft_unset(av[1], env);
//     ft_env(env);    
//     ft_export(nullstr, env);
// }