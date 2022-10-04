/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:00:01 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/19 18:13:06 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_env(t_env *env_list)
{
	int		i;
	t_env	*aux;

	i = 0;
	aux = env_list;
	while (aux != NULL)
	{
		if (aux->key)
			free(aux->key);
		if (aux->value)
			free(aux->value);
		env_list = aux;
		aux = aux->next;
		if (env_list)
			free(env_list);
	}
}
