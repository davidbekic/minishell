/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/27 14:47:24 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_space(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '.' && str[1] == 0)
	{
		ft_printf(2, "minishell: .: filename argument required\n");
		ft_printf(2, ".: usage: . filename [arguments]\n");
		g_exit = 2;
		return (1);
	}	
	while (str[++i] != 0)
	{
		if (!((str[i]) == '\t' || (str[i]) == '\v'
				|| (str[i]) == '\r' || (str[i]) == '\n'
				|| (str[i]) == '\f' || (str[i]) == 32))
			return (0);
	}
	return (1);
}

static int	ft_quote_checker(char *str)
{
	unsigned char	quote_type;

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

static int	ft_many_pipes_redirs(char *str)
{
	int	i;

	i = -1;
	while (str[i + 2] != 0)
	{
		if (((str[i] == '>' || str[i] == '<' || str[i] == '|')
			&& (str[i + 1] == '>' || str[i + 1] == '<' || str[i + 1] == '|')
			&& (str[i + 2] == '>' || str[i + 2] == '<' || str[i + 2] == '|')) 
			|| ((str[i] == '>' && str[i + 1] == '<')) || (str[i] == '<' && str[i + 1] == '>')
			|| (str[i] == '>' && str[i + 1] == '|') || (str[i] == '<' && str[i + 1] == '|'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_syntax_checker(char *str)
{
	int	i;
	int	err_flag;

	i = 0;
	err_flag = 0;
	while (str[i] != 0)
	{
		if (!err_flag && (str[i] == '>' || str[i] == '<' || str[i] == '|'))
		{
			if (!err_flag)
				err_flag = 1;
		}
		else if (err_flag && (!(str[i] == '>' || str[i] == '<'
					|| str[i] == '|' || str[i] == 32)))
			err_flag = 0;
		i++;
	}
	if (str[0] == '|')
		err_flag = 1;
	if (err_flag || ft_many_pipes_redirs(str))
	{
		ft_printf(2, "minishell: `%s': syntax error\n", str);
		return (1);
	}
	return (0);
}

int	ft_prompt_parser(char **buf, t_env *env)
{
	if (ft_quote_checker(*buf))
	{
		ft_printf(2, "minishell: open quotes\n");
		return (258);
	}
	if (ft_syntax_checker(*buf))
		return (258);
	if (ft_counter(*buf, 32) > MAXARGS)
	{
		ft_printf(2, "too many arguments\n");
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
