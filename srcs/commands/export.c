/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:32:49 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/20 12:45:28 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_update_var(char *key_value, int value_start, t_env *list)
{
	t_env	*elem;
	t_env	*aux;
	int		i;
	char	key[100];

	i = 0;
	aux = list;
	printf("key_value in update var: %s\n", key_value);
	strncpy(key, key_value, value_start - 1);
	elem = ft_find_elem(list, key_value);
	// CREATING ELEMENT
	if (!elem)
	{
		while (strcmp(list->next->key, "_") != 0)
			list = list->next;
		elem = ft_create_elem(elem, key_value, ft_find_value(key_value));
		aux = list->next;
		list->next = elem;
		elem->next = aux;
	}
	// UPDATE VARIABLE
	else
	{
		while (key_value[value_start + i] != 0)
		{
			i++;
			elem->value[i - 1] = key_value[value_start + i - 1];
		}
		elem->value[i] = 0;
	}
}

void    ft_export(char *arg, t_env *env)
{
	unsigned char	key_end;
	unsigned char	value_start;

	//printf("key_end: %d\value_start: %d\n", key_end, value_start);
	printf("ENTERING FT_EXPORT\n");
	printf("arg: %s\n", arg);
	key_end = ft_find_key(arg);
	printf("key_end: %d\n", key_end);
	value_start = ft_find_value(arg);
	// IF NOTHING -- SHOW ALPHABETIC ENV
	if (!arg)
	{
		printf("entering alphabetic condition\n");
		ft_alphabetic_env(env);
	}
	// IF ONLY KEY
	else if (key_end != 0 && value_start == 0)
		printf("minishell: PLEASE GIVE VALUE TO VARIABLE\n");
	// MAKE NEW OR UPDATE ENV VAR
	else
		ft_update_var(arg, value_start, env);
}

/*
void    ft_export(char *key, char *value, t_env *list)
{
	// IF ONLY KEY
	if (key && !value)
		printf("nada\n");
	// IF NOTHING -- SHOW ALPHABETIC ENV
	else if (!key || !value)
		ft_alphabetic_env(list);
	// MAKE NEW OR UPDATE ENV VAR
	else
		ft_update_var(key, value, list);
}
*/
