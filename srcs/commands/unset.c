/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/22 14:29:09 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env    *ft_unset(char *key, t_env *env_list)
{
    t_env   *to_delete;
    t_env   *to_redirect;
    
    printf("ENTERING FT_UNSET: %s\n", key);
    if (strcmp(key, "_") == 0)  // IF TRYING TO CHANGE LAST ENV VARIABLEE
        return (env_list);
    to_delete = ft_find_elem(env_list, key);
    if (!to_delete)
        return (env_list);
    to_redirect = ft_find_elem_before(env_list, key);
    if (!to_redirect)
        return (env_list);
    printf("to_delete->key: %s\n", to_delete->key);
    printf("to_redirect->key: %s\n", to_redirect->key);
    if (!to_redirect)
        env_list = to_delete->next;
    else
        to_redirect->next = to_delete->next;
    printf("to_redirect->next now pointing to: %s\n", to_redirect->next->key);
    free(to_delete->key);
    free(to_delete->value);
    free(to_delete);
    printf("REACHED END OF FT_UNSET\n");
    return (env_list);
}
