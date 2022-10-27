/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 12:18:41 by dbekic           ###   ########.fr       */
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

static int	ft_in_find(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp >= estr)
	{
		if (*tmp == '"')
			return (1);
		tmp--;
	}
	return (0);
}

static void	ft_find_end(char **equotes, char **estr, char token)
{
	static unsigned char	in_quote;

	in_quote = token;
	while (*equotes < *estr && !ft_strchrflag("\t\r\n\v ", **equotes, in_quote))
	{
		if (**equotes == token && (**equotes != in_quote) && !in_quote)
			in_quote = **equotes;
		else if (**equotes == in_quote)
			in_quote = 0;
		*equotes = *equotes + 1;
		if (*equotes == *estr || **equotes == ' ')
		{
			*equotes = *equotes - 1;
			break ;
		}
	}
}

int	ft_in_quotes(char **tmp, char **estr, char token)
{
	char	*equotes;
	char	*aux;

	equotes = *tmp;
	ft_find_end(&equotes, estr, token);
	while (*equotes == token)
		equotes--;
	aux = equotes;
	while (equotes > *tmp && ft_in_find(&aux, *tmp))
	{
		if (*equotes == token)
			ft_swap(equotes + 1, equotes, 1);
		equotes--;
		if (equotes == *tmp && ft_in_find(&aux, *tmp))
		{
			equotes = aux;
			if (*(aux - 1) == token)
				aux--;
			if (*aux == token)
				aux--;
		}
	}
	while (aux < *estr && !ft_strchr("\"\'", *aux) && !ft_strchr("\t\r\n\v ", *aux))
		aux++;
	*tmp = aux;
	return (**tmp && ft_strchr("\"", **tmp));
}

int	ft_true_quotes(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && !ft_strchr("\t\r\n\v ", *tmp))
	{
		if (*tmp == '"' || *tmp == '\'')
			return (1);
		tmp++;
	}
	return (0);
}

int	ft_change_token(char **pstr, char *estr)
{
	char			*tmp;
	int				counter;
	int				len;
	int				ret;
	unsigned char	in_quote;
	char			copy[256];
	int				i;

	tmp = *pstr;
	counter = 0;
	len = 0;
	i = 0;
	ft_memset(copy, 0, sizeof(copy));
	while (tmp < estr && !ft_strchrflag("\t\r\n\v ", *tmp, in_quote)
		&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
		if (ft_strchr("\"\'", *tmp) && (*tmp != in_quote) && !in_quote)
		{
			in_quote = *tmp;
			counter++;
		}
		else if (*tmp == in_quote)
		{
			in_quote = 0;
			counter++;
		}
		else if (*tmp != in_quote)
		{
			copy[i] = *tmp;
			i++;
		}
		tmp++;
		len++;
	}
	if (counter == 2 && len == 2)
		return (0);
	i = ft_strlen(copy);
	while (ft_strlen(copy) < (size_t)len)
	{
		copy[i] = 32;
		i++;
	}
	i = 0;
	tmp = *pstr;
	ret = len;
	while (tmp < estr && len > 0)
	{
		*tmp = copy[i];
		i++;
		len--;
		tmp++;
	}
	return (ret - counter);

}