/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/08 19:25:54 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_unset(t_env *env_list, char *key)
{
    t_env   *to_delete;
    t_env   *to_redirect;
    t_env   *redirect_target;
    
    to_redirect = ft_find_elem_before(env_list, key);
    to_delete = ft_find_elem(env_list, key);
    to_redirect->next = to_delete->next;
    free(to_delete->key);
    free(to_delete->value);
    free(to_delete);
}