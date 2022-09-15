/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:15:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/15 13:04:50 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_key_value_and_maybe_rest(char *key, char *value)
{
	if (key)
	{
		free(key);
		key = NULL;
	}
	if (value)
	{
		free(value);
		value = NULL;
	}
}

t_env	*ft_create_elem(t_env *new, char *key, char *value)
{
	int	i;

	i = 0;
	new = (t_env *) calloc(1, sizeof(t_env));
	if (!new)
			return (NULL);
	new->key = (char *) calloc(strlen(key) + 1, 1);
	if (!new->key)
		return (NULL);
	new->value = (char *) calloc(strlen(value) + 1, 1);
	if (!new->value)
		return (NULL);
	while (key[i++] != 0)
	new->key[i - 1] = key[i - 1];
	i = 0;
	while (value[i++] != 0)
		new->value[i - 1] = value[i - 1];
	free_key_value_and_maybe_rest(key, value);
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
