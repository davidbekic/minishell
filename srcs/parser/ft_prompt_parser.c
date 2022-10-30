/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/30 02:51:32 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int	ft_is_space(char *str)
{
	int	i;

	i = -1;
	// if (str[0] == '.' && str[1] == 0)
	// {
	// 	ft_printf(2, "minishell: .: filename argument required\n");
	// 	ft_printf(2, ".: usage: . filename [arguments]\n");
	// 	g_exit = 2;
	// 	return (1);
	// }	
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
	char			*head;

	quote_type = 0;
	head = str;
	while (*str != 0)
	{
		if ((*str == '\"' || *str == '\'')
			&& (*str != quote_type) && !quote_type)	
			quote_type = *str;
		else if (*str == quote_type)
			quote_type = 0;
			str++;
	}
	str = head;
	return (quote_type);
}

int	ft_prompt_parser(char **buf, t_env *env)
{
	if (ft_quote_checker(*buf))
	{
		ft_printf(2, "minishell: open quotes\n");
		return (258);
	}
	if (ft_counter(*buf, 32) > MAXARGS)
	{
		ft_printf(2, "too many arguments\n");
		return (1);
	}
	if (ft_strlen(*buf) > 4096)
	{
		ft_printf(2, "too long prompt\n");
		return (1);
	}
	ft_prompt_expander(buf, env);
	if (ft_strlen(*buf) > 4096)
	{
		ft_printf(2, "too long prompt\n");
		return (1);
	}
	return (0);
}
