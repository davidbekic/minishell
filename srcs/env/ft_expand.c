/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:32:59 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/06 16:51:58 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *ft_expand(t_env *env, char *key)
{
    int i;
    void *ret;
    char temp_buf[4096];

    i = 0;
    ret = NULL;
    ft_memcpy(temp_buf, key, strlen(key));
    temp_buf[ft_strlen(key)] = 0;
	while (temp_buf[i] != 0)
	{
		if (key[i] >= '0' && key[i] <= '9' && i == 0)
			return (NULL);
		if (!(key[i] >= 'a' && key[i] <= 'z') && !(key[i] >= 'A' && key[i] <= 'Z')
			&& key[i] != '_')
            break ;
		i++;
	}
	temp_buf[i] = 0;
    ret = (t_env *) ft_find_elem(env, temp_buf);
    if (!ret)
        return (NULL);
    else
    return (ft_find_elem(env, temp_buf)->value);
}
