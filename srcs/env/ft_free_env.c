/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:00:01 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/30 02:53:54 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

void	ft_free_envp(char **envp)
{
	char	**head;

	head = envp;
	while (*envp)
	{
		if (*envp)
			free(*envp);
		*envp = NULL;
		envp++;
	}
	if (head)
		free(head);
}

void	ft_free_env(t_env *env, int err)
{
	t_env	*aux;

	aux = env;
	if (env->envp)
		ft_free_envp(env->envp);
	while (aux != NULL)
	{
		if (aux->key)
			free(aux->key);
		if (aux->value)
			free(aux->value);
		env = aux;
		aux = aux->next;
		if (env)
			free(env);
	}
	if (err)
	{
		ft_putstr_fd("malloc failure, please restart Shell\n", 2);
		exit(1);
	}
}
