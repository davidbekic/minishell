/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/27 17:10:41 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int ft_quote_checker(char *str)
{
	int				i;
	unsigned char	quote_type;
	unsigned char	in_quote;

	i = 0;
	quote_type = 0;
	in_quote = 0;
	while (str[++i] != 0)
	{
		if ((str[i] == '\"' || str[i] == '\'') && (str[i] != quote_type) && (in_quote == 0))
		{
			in_quote = 1;
			quote_type = str[i];
		}
		else if (str[i] == quote_type )
		{
			in_quote = 0;
			quote_type = 0;
		}
	}
	if (in_quote)
		return (1);
	else
		return (0);
}

static int ft_syntax_checker(char *str)
{
    int i;
    int pipe_redir_count;
    
    i = 0;
    pipe_redir_count = 0;
    while (str[++i] != 0)
    {
        if (str[0] == '|')
        {
            perror("minishell: parse error near `|'\n");
            return (1);
        }
        // if ((str[i] == '>' || str[i] == '<' || str[i] == '|') && (str[i+1] == 0 || str[i+1] == ' '))
        // {
        //     perror("minishell: parse error near `\\n'\n");
        //     return (1);
        // }
        
    }
    return (0);
}


int ft_prompt_parser(char *str, t_env *env)
{
    if (ft_quote_checker(str))
    {
        perror("minishell: open quotes\n");
        return (1);
    }
    if (ft_syntax_checker(str))
        return (1);
    return (0);
    //prompt_expander(str, env);   
}