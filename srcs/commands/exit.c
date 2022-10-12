/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:35 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/12 13:12:04 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_exit(char **names)
{
    unsigned char ret;

    ret = 0;
    // ret = g_exit;
    if (names[2])
    {
        printf("minishell: exit: too many arguments\n");
        ret = 1;
    }
    else if (names[1])
        ret = (unsigned char) ft_atoi(names[1]);
    exit (ret); 
}