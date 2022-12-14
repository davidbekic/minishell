/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/31 10:04:49 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static int	ft_list_redir(char **tmp, int *result)
{
	if (**tmp == 0)
		return (0);
	else if (**tmp == '<')
	{
		*tmp = *tmp + 1;
		if (**tmp == '<')
		{
			*result = '-';
			*tmp = *tmp + 1;
		}
	}
	else if (**tmp == '>')
	{
		*tmp = *tmp + 1;
		if (**tmp == '>')
		{
			*result = '+';
			*tmp = *tmp + 1;
		}
	}
	return (1);
}

static int	ft_case(char **tmp, char **estr, int *result, int flag)
{
	if (**tmp == 0)
		return (0);
	else if (**tmp == '|' && flag == 0)
	{
		*tmp = *tmp + 1;
		if (ft_find(tmp, *estr, "|"))
			ft_error("syntax error near unexpected token\n", 258);
	}
	else if (flag == 0 && (**tmp == '<' || **tmp == '>'))
		ft_list_redir(tmp, result);
	else
	{
		*result = 'z';
		while (*tmp < *estr && !ft_strchrflag("\t\r\n\v ", **tmp, flag)
			&& !ft_strchrflag("<|>", **tmp, flag))
		{
			if (flag > 0)
				flag--;
			*tmp = *tmp + 1;
		}
	}
	return (1);
}

int	ft_fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork", 1);
	return (pid);
}

int	ft_find(char **pstr, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr(tokens, *tmp));
}

int	ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char		*tmp;
	int			result;
	int			flag;

	flag = ft_true_quotes(pstr, estr);
	if (flag != 0)
	{
		flag = ft_change_token(pstr, estr);
		if (flag == 0)
			flag = 1;
	}
	tmp = *pstr;
	while (tmp < estr && ft_strchrflag("\t\r\n\v ", *tmp, flag))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	result = *tmp;
	if (ft_case(&tmp, &estr, &result, flag) == 0)
		return (0);
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
