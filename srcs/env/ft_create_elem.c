/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:15:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/19 18:43:05 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_create_elem(t_env *new, char *key_value, int value_start)
{
	int	i;

	i = 0;
	new = (t_env *) calloc(1, sizeof(t_env));
	if (!new)
			return (NULL);
	new->key = (char *) calloc(value_start + 1, 1);
	if (!new->key)
		return (NULL);
	new->value = (char *) calloc(strlen(key_value) + 1 - value_start, 1);
	if (!new->value)
		return (NULL);
	while (++i < value_start)
	{
		new->key[i - 1] = key_value[i - 1];
	}
	i = 0;
	while (*(key_value + value_start + i) != 0)
	{
		new->value[i] = key_value[value_start + i];
		printf("%s: %s\n", new->key, new->value);
		i++;
	}
	new->next = NULL;
	return (new);
}

// t_env	*ft_create_elem(t_env *new, char *env_variable)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	new = (t_env *) calloc(1, sizeof(t_env));
// 	if (new == NULL)
// 		return (NULL);
// 	while (env_variable[i] != '=' && env_variable[i] != 0)
// 		i++;
// 	new->key = calloc(i + 1, 1);
// 	if (!new->key)
// 		return (NULL);
// 	i = 0;
// 	while (env_variable[i++] != '=' && env_variable[i] != 0)
// 		new->key[i - 1] = env_variable[i - 1];
//     // WRONG CALLOC SIZE SURELY?
//     //printf("strlen(env_var) - i: %lu\n", strlen(env_variable) - i);
// 	new->value = calloc(strlen(env_variable) - i + 1, 1);
// 	if (!new->value)
// 		return (NULL);
// 	while (env_variable[i] != 0)
// 		new->value[j++] = env_variable[i++];
// 	new->next = NULL;
// //    printf("env_variable: %s\n", env_variable);
// 	return (new);
// }
