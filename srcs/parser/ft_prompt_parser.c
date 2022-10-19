/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 18:20:04 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit;

static int	ft_quote_checker(char *str)
{
	unsigned char	quote_type;

	quote_type = 0;
	while (*str != 0)
	{
		if ((*str == '\"' || *str == '\'')
			&& (*str != quote_type) && !quote_type)
			quote_type = *str;
		else if (*str == quote_type)
			quote_type = 0;
			str++;
	}
	return (quote_type);
}

static int	ft_syntax_checker(char *str)
{
	int	i;
	int	err_flag;

	i = 0;
	err_flag = 0;
	while (str[i] != 0)
	{
		if (str[0] == '|')
			return (1);
		if ((str[i] == '>' || str[i] == '<' || str[i] == '|'))
		{
			if (!err_flag)
				err_flag = 1;
		}
		else if (err_flag && (!(str[i] == '>' || str[i] == '<'
					|| str[i] == '|' || str[i] == 32)))
			err_flag = 0;
		i++;
	}
	if (err_flag)
		return (1);
	return (0);
}

int	ft_prompt_parser(char **buf, t_env *env)
{
	if (ft_quote_checker(*buf))
	{
		perror("minishell: open quotes\n");
		return (124);
	}
	if (ft_syntax_checker(*buf))
	{
		g_exit = 258;
		return (1);
	}
	if (ft_strlen(*buf) > 4096)
	{
		printf("too long prompt\n");
		return (1);
	}
	ft_prompt_expander(buf, env);
	if (ft_strlen(*buf) > 4096)
	{
		printf("too long prompt\n");
		return (1);
	}
	return (0);
}
