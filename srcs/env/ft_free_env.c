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

void	ft_free_envp(char **envp)
{
	char	**head;

	head = envp;
	printf("hello?\n");
	while (*envp)
	{
		if (*envp)
			free(*envp);
		*envp = NULL;
		envp++;
	}
	if (head)
		free(head);
	// head = NULL;
}

void	ft_free_env(t_env *env)
{
	int		i;
	t_env	*aux;
	t_env	*head;

	i = 0;
	aux = env;
	head = env;
	if (env->envp)
	{	
		ft_free_envp(env->envp);
	}
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
}
