/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/14 13:34:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

int	ft_quotes(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		count;

	tmp = *pstr;
	count = 0;
	while (tmp < estr && ft_strchr("\"", *tmp) && count++ >= 0)
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	while (tmp < estr && !ft_strchr("\"", *tmp))
	{
//		printf("entro en while tmp es %c\n", *tmp);
		tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\"", *tmp) && count--)
		tmp++;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
	{
//		printf("entro en while espacio\n");
		tmp++;
	}
	*pstr = tmp;
	return (*tmp && ft_strchr("\"", *tmp));
}

int	ft_quotes_simple(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		count;

	tmp = *pstr;
	count = 0;
	while (tmp < estr && ft_strchr("\'", *tmp) && count++ >= 0)
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	while (tmp < estr && !ft_strchr("\'", *tmp))
	{
//		printf("entro en while tmp es %c\n", *tmp);
		tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\'", *tmp) && count--)
		tmp++;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
	{
//		printf("entro en while espacio\n");
		tmp++;
	}
	*pstr = tmp;
	return (*tmp && ft_strchr("\'", *tmp));
}
