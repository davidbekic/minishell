/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/08 18:31:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_unset(char **names, t_env **env)
{
    t_env           *to_delete;
    t_env           *to_redirect;
    unsigned char   ret;
    
    ret = 0;
    while (*names++)
    {
        if (ft_var_name_check(*names, ft_strlen(*names)))
        {
            ret = 1;
            printf("minishell: unset: `%s' not a valid identifier\n", *names);
            continue ;
        }
        to_delete = ft_find_elem(*env, *names);
        if (!to_delete || !*names || strcmp(*names, "_") == 0)
            continue ;
        to_redirect = ft_find_elem_before(*env, *names);
        if (!to_redirect)
            *env = to_delete->next;
        else
            to_redirect->next = to_delete->next;
        free(to_delete->key);
        free(to_delete->value);
        free(to_delete);
    }
    return (ret);
}

// int main(int ac, char **av, char **main_env)
// {
//     int i;
//     t_env *env;
//     char **nullstr;

// 	nullstr = malloc(200);
// 	nullstr[0] = malloc(200);
// 	nullstr[1] = malloc(200);
// 	nullstr[2] = malloc(200);
// 	nullstr[3] = malloc(200);
// 	nullstr[0] = "unset";
// 	nullstr[1] = "USER1";
// 	nullstr[2] = "PWD";
// 	nullstr[3] = "1HOME";
// 	nullstr[4] = NULL;

//     i = 0;
//     env = ft_init_env(main_env);
    
    
//     printf("ret from env in main: %d\n", ft_unset(nullstr, &env));
//     ft_env(env);    
//     ft_free_env(env);
//     //ft_export(nullstr, env);
// }