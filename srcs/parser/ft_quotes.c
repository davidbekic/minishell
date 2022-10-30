/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/30 02:52:04 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

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

void	ft_fillspace(char copy[256], int len)
{
	int	i;
	(void) len;
	//printf("copy: %s\n", copy);
	i = ft_strlen(copy);
	//i = 10;
	while (i < 256)
	{
		copy[i] = ' ';
		i++;
	}
	
}

static int	ft_getcleaned(char **pstr, char *estr, char copy[256], int *counter)
{
	char			*tmp;
	unsigned char	in_quote;
	int				len;
	int				i;

	in_quote = 0;
	ft_memset(copy, 0, sizeof(copy[256]));
	tmp = *pstr;
	len = 0;
	i = 0;
	while (tmp < estr && !ft_strchrflag("\t\r\n\v ", *tmp, in_quote)
		&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
		if (!ft_in_quotes(tmp, &in_quote, counter) && *tmp != in_quote)
		{
			copy[i] = *tmp;
			i++;
		}
		tmp++;
		len++;
	}
	ft_fillspace(copy, len);
	return (len);
}

static int	ft_copycleaned(char **pstr, char *estr, char copy[256])
{
	char	*tmp;
	int		ret;
	int		counter;
	int		len;
	int		i;
	
	counter = 0;
	len = ft_getcleaned(pstr, estr, copy, &counter);
	tmp = *pstr;
	ret = len;
	i = 0;
	while (tmp < estr && len > 0)
	{
		*tmp = copy[i];
		i++;
		len--;
		tmp++;
	}
	return (ret - counter);
}

int	ft_change_token(char **pstr, char *estr)
{
	int				ret;
	char			copy[256];

	ft_memset(copy, 0, sizeof(copy));
	ret = ft_copycleaned(pstr, estr, copy);
	return (ret);
}
