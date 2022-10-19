/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:16:58 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 18:17:36 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_home_check(char *str, int pos)
{
	if (str[pos] == '~' && str[pos - 1] != '~' && str[pos + 1] != '~'
		&& (str[pos + 1] == '/' || str[pos + 1] == 0 || str[pos + 1] == 32)
		&& (str[pos - 1] == 32 || str[pos - 1] == 0))
		return (1);
	return (0);
}

static int	ft_is_exit(char *str)
{
	if (!(strncmp(str, "$?", 2)))
		return (1);
	else
		return (0);
}

void	ft_prompt_expander(char **buf, t_env *env)
{
	int				i;
	int				j;
	char			dump[4096];
	unsigned char		quote_type;

	i = 0;
	j = 0;
	quote_type = 0;
	bzero(dump, 4096);
	ft_memcpy(dump, *buf, ft_strlen(*buf));
	while (*(dump + i) && j < 4096)
	{
		if ((dump[i] == '\"' || dump[i] == '\'') && (dump[i] != quote_type) && !quote_type)
			quote_type = dump[i];
		else if (dump[i] == quote_type)
			quote_type = 0;
		if (ft_is_exit(dump + i) && quote_type != '\'')
		{
			ft_memcpy(*(buf) + j, ft_itoa(g_exit), ft_strlen(ft_itoa(g_exit)));
			j += ft_strlen(ft_itoa(g_exit));
		}
		else if (ft_home_check(dump, (i)) && !quote_type)
		{
			ft_memcpy(*(buf) + j, ft_expand(env, "HOME"), ft_strlen(ft_expand(env, "HOME")) + 1);
			i++;
			j += ft_strlen(ft_expand(env, "HOME"));
		}
		if (dump[i] == '$' && quote_type != '\'')
		{
			if (ft_expand(env, dump + i + 1) != NULL)
				ft_memcpy(*(buf) + j, ft_expand(env, dump + i + 1), ft_strlen(ft_expand(env, dump + i + 1)) + 1);
			if (!ft_var_name_stop(dump + i + 1) && dump[i] != '~')
			ft_memcpy(*buf + (++j - 1), dump + (i), 1);
			j += ft_strlen(ft_expand(env, dump + i + 1));
			i += ft_var_name_stop(dump + i + 1) + 1;
			continue ;
		}
		ft_memcpy(*buf + (++j - 1), dump + (++i - 1), 1);
	}
	buf[0][j] = 0;
}