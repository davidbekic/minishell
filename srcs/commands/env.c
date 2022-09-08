/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:39:37 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/08 16:39:38 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_env(t_env *env_list)
{
    int     i;
    t_env   *aux;

    i = 0;
    aux = env_list;
    while (aux->next != NULL)
    {
        printf("%s=%s\n", aux->key, aux->value);
        aux = aux->next;
        i++;
    }
    printf("%s=%s\n", aux->key, aux->value);
}