/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:20 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/09 14:42:52 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_init_env(char **main_env)
{
	t_env	*head;
	t_env	*current;
	t_env	*temp;
	int		i;

	head = ft_create_elem(head, ft_find_key(main_env[0]), ft_find_value(main_env[0]));
	if (!head)
	{
		free_env(head);
		return (NULL);
	}
	temp = head;
	i = 1;
	while (main_env[i] != NULL)
	{
		current = ft_create_elem(current, ft_find_key(main_env[i]), ft_find_value(main_env[i]));
		if (!current)
		{
			free_env(head);
			return (NULL);
		}
		temp->next = current;
		temp = current;
		i++;
	}
	return (head);
}
