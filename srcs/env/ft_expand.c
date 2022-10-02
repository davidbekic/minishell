/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:32:59 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/13 13:25:52 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *ft_expand(t_env *env_list, char *key)
{
    int i;
    char temp_buf[200];

    i = 0;
    ft_memcpy(temp_buf, key, strlen(key));
	while (key[i] != 0)
	{
		if (key[i] >= '0' && key[i] <= '9' && i == 0)
			return (NULL);
		if (!(key[i] >= 'a' && key[i] <= 'z') && !(key[i] >= 'A' && key[i] <= 'Z')
			&& key[i] != '_')
        {
			temp_buf[i] = 0;
            printf("in here ever?\n");
            break ;
        }
		i++;
	}
    printf("temp_buf: %s\n", temp_buf);
    return (ft_find_elem(env_list, temp_buf)->value);
}
