/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 11:53:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_swap(void *dest, void *src, size_t count)
{
	char	tmp;
	char	*ptr;
	char	*ptr_src;

	ptr = (char *)dest;
	ptr_src = (char *)src;
	tmp = *ptr;
	while (count--)
	{
		*ptr = *ptr_src;
		*ptr_src = tmp;
	}
	return (dest);
}

int	ft_quotes(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		count;

	tmp = *pstr;
	if (*tmp == 39)
		ft_quotes_simple(pstr, estr, ftoken, eftoken);
	else
	{
		count = 0;
		while (tmp < estr && ft_strchr("\"", *tmp) && count++ >= 0)
			tmp++;
		if (ftoken)
			*ftoken = tmp;
		while (tmp < estr && !ft_strchr("\"", *tmp))
			tmp++;
		if (eftoken)
			*eftoken = tmp;
		while (tmp < estr && ft_strchr("\"", *tmp) && count--)
			tmp++;
		while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
			tmp++;
		*pstr = tmp;
	}
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
		tmp++;
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\'", *tmp) && count--)
		tmp++;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr("\'", *tmp));
}
