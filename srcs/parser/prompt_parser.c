/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/03 18:00:00 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_var_name_stop(char *str)
{
	int	i;
	char	buf[100];

	i = 0;
	ft_memcpy(buf, str, ft_strlen(buf)); // putting only var_NAME in buf
	buf[ft_strlen(buf)] = 0; // memcpy not NULL-terminating fro some reason.
	while (str[i] != 0) 
	{
		if (str[i] >= '0' && str[i] <= '9' && i == 0)
			return (0);
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')
			&& str[i] != '_' && !(str[i] >= '0' && str[i] <= '9'))
        {
            printf("entering with: %c\n", str[i]);
			return (i);
        }
		i++;
	}
	return (i);
}

static int ft_quote_checker(char *str)
{
	unsigned char	quote_type;

	quote_type = 0;
	while (*str != 0)
	{
		if  ((*str == '\"' || *str== '\'') 
          && (*str != quote_type ) && !quote_type)
			quote_type = *str;
		else if (*str == quote_type)
			quote_type = 0;
        str++;
	}
	return (quote_type);
}

static int ft_syntax_checker(char **str)
{
    int i;
    int pipe_redir_count;
    
    i = 0;
    pipe_redir_count = 0;
    while (*str[++i] != 0)
    {
        if (*str[0] == '|')
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

void    prompt_expander(char **buf, t_env *env)
{
	unsigned char	quote_type;
    int             i;
    int             j;
    char            dump[4096];
    
	i = 0;
    j = 0;
	quote_type = 0;
    bzero(dump, 4096);
    ft_memcpy(dump, *buf, ft_strlen(*buf));
	while (dump[i] != 0)
	{
		if  ((dump[i] == '\"' || dump[i]== '\'') && (dump[i] != quote_type ) && !quote_type)
			quote_type = dump[i];
		else if (dump[i] == quote_type)
			quote_type = 0;
        if (dump[i] == '$' && quote_type != '\'')
        {
            if (ft_expand(env, dump + i + 1) == NULL)
            {
                ft_memcpy(*buf + i + j, "", 1);      
                j -= ft_var_name_stop(dump + i + 1) + 2;
                i -= j;
            }
            else 
            {
                memcpy(*(buf) + i + j, ft_expand(env, dump + i + 1), ft_strlen(ft_expand(env, dump + i + 1)) + 1);
                i += ft_var_name_stop(dump + i + 1) + 1;
                j = ft_strlen(*(buf) + i);
            }
            continue ;
        }
        ft_memcpy(*buf + i + j, dump + i, 1);
        i++;
	}
    buf[0][i + j] = 0;
    printf("expanded_buf: %s\n", *buf);
}

int ft_prompt_parser(char **buf, t_env *env)
{
    if (ft_quote_checker(*buf))
    {
        perror("minishell: open quotes\n");
        return (124);
    }
    // if (ft_syntax_checker(buf))
    //     return (1);
    prompt_expander(buf, env);   
    
    return (0);
}
