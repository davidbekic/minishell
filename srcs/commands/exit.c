/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:35 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/10 15:00:42 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_exit(char **names)
{
    unsigned char ret;

    ret = 0;
    if (names[2])
    {
        printf("minishell: exit: too many arguments\n");
        ret = 1;
    }
    else if (names[1])
        ret = (unsigned char) ft_atoi(names[1]);
    else
        ret = 0;
    printf("exit\n");
    printf("names[0]: %p\n", names[0]);
    free(names[0]);
    printf("exit returning %d\n", ret);
    exit (ret);
}