/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:34:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 17:22:46 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	ft_is_builtin(char *buf)
{
	int	marker;
	int	i;
	char	*head;
	char	comparison_str[4096];
	static char	*built_ins[400] = {"echo", "export", "unset", "pwd", "cd", "exit", "env"};
	
	ft_bzero(comparison_str, 4096);
	marker = 0;
	i = -1;
	head = buf;
	while ((*buf))
	{
		if ((*buf) == '|' || (*buf) == '<' || (*buf) == '>')
			return (0);
		buf++;
	}
	buf = head;
	while ((*buf))
	{
		if (*buf == 32 || *buf == 0)
			break ;
		buf++;
		marker++;
	}
	buf = head;
	while (built_ins[++i])
	{
		if (!(ft_strcmp(ft_memcpy(comparison_str, buf, marker), built_ins[i])))
			return (1);
	}
	return (0);
}

struct cmd	*builtparse(char *str)
{
	char		*estr;
	struct cmd	*cmd;

	estr = str + ft_strlen(str);
	cmd = builtexec(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax", 1);
	}
	terminate(cmd);
	return (cmd);
}

struct cmd	*builtexec(char **pstr, char *estr)
{
	char			*ftoken;
	char			*eftoken;
	int				token;
	struct cmd		*ret;
	struct doexec	*cmd;

	ret = buildexec();
	cmd = (struct doexec *)ret;
	while ((token = gettoken(pstr, estr, &ftoken, &eftoken)) != 0)
	{
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
			break ;
	}
	ft_setcmd(&cmd, ftoken, eftoken, 1);
	return (ret);		
}