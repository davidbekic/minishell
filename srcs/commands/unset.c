/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/13 18:40:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(char **names, t_env **env)
{
	unsigned char	ret;
	t_env			*to_delete;
	t_env			*to_redirect;

	ret = 0;
	while (*(names++ + 1) != NULL)
	{
		if (ft_var_name_check(*names, ft_strlen(*names)))
		{
			ret = 1;
			printf("minishell: unset: `%s' not a valid identifier\n", *names);
			continue ;
		}
		to_delete = ft_find_elem(*env, *names);
		if (!to_delete || !*names || strcmp(*names, "_") == 0)
			continue ;
		to_redirect = ft_find_elem_before(*env, *names);
		if (!to_redirect)
			*env = to_delete->next;
		else
			to_redirect->next = to_delete->next;
		free(to_delete->key);
		free(to_delete->value);
		free(to_delete);
	}
	return (ret);
}
