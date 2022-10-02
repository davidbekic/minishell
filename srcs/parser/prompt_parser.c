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

char *prompt_expander(char **str, t_env *env)
{
	unsigned char	quote_type;
    int             i;
    int             j;
    char            *expanded_buf;
    
	quote_type = 0;
    expanded_buf = malloc(2000);
	i = 0;
    j = 0;
	while (str[0][i] != 0)
	{
		if  ((str[0][i] == '\"' || str[0][i]== '\'') 
          && (str[0][i] != quote_type ) && !quote_type)
			quote_type = str[0][i];
		else if (str[0][i] == quote_type)
			quote_type = 0;
        if (str[0][i] == '$' && quote_type != '\'')
        {
            ft_memcpy(expanded_buf + i, ft_expand(env, *(str) + i + 1), strlen(ft_expand(env, *(str) + i + 1)) + 1);
            printf("expanded_buf: %s\n", expanded_buf);
            j = strlen(ft_expand(env, *(str) + i + 1));
            i += 1;
            continue ;
        }

        ft_memcpy(expanded_buf + i + j, *str + i, 1);
        i++;
	}
    expanded_buf[i + j] = 0;
    printf("expanded_buf: %s\n", expanded_buf);
    return(expanded_buf);
}

int ft_prompt_parser(char **buf, t_env *env)
{
    if (ft_quote_checker(*buf))
    {
        perror("minishell: open quotes\n");
        return (1);
    }
    // if (ft_syntax_checker(buf))
    //     return (1);
    *buf = prompt_expander(buf, env);   
    return (0);
}
