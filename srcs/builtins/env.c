/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:39:37 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 12:21:27 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_envsize(t_env *env)
{
	t_env	*ptr;
	int		counter;

	counter = 0;
	ptr = env;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}

void	ft_alphabetic_write(t_env *temp)
{
	if (ft_strncmp(temp->key, "_", 3) != 0)
	{
		ft_printf(1, "declare -x %s", temp->key);
		if (temp->value)
			ft_printf(1, "=\"%s\"", temp->value);
		ft_printf(1, "\n");
	}

}

void	ft_alphabetic_env(t_env *env)
{
	int		i;
	int		j;
	t_env	*aux;
	t_env	*temp;

	i = 0;
	j = 0;
	aux = env;
	temp = aux;
	while (j < ft_envsize(env) - 1)
	{
		while (aux != NULL)
		{
			if (ft_strncmp(temp->key, aux->key, 50) < 0)
				i++;
			aux = aux->next;
		}
		if (i == ft_envsize(env) - j - 2)
		{
			ft_alphabetic_write(temp);
			aux = env;
			temp = env;
			j++;
			i = 0;
			continue ;
		}
		temp = temp->next;
		aux = env;
		i = 0;
	}
}

int	ft_env(t_env *env, char **names)
{
	int		i;
	t_env	*aux;

	if (*(names + 1))
	{
		ft_printf(2, "env: %s: no such file or directory\n", *(names + 1));
		return (127);
	}
	i = 0;
	aux = env;
	while (aux != NULL)
	{
		if (aux->value != NULL)
		{
			ft_printf(1, "%s=%s\n", aux->key, aux->value);
		}
	aux = aux->next;
	i++;
	}
	return (0);
}
