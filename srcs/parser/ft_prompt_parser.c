/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:45:26 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/18 22:39:37 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// extern int g_exit;

static int	ft_var_name_stop(char *str)
{
	int     i;
	char	buf[4096];

	i = 0;
	ft_memcpy(buf, str, ft_strlen(str) + 1); // putting only var_NAME in buf
	while (str[i] != 0) 
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')
			&& str[i] != '_' && !i && str[i] != '$')
            return (1);
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')
			&& str[i] != '_' && !(str[i] >= '0' && str[i] <= '9'))
			    return (i);
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

static int ft_syntax_checker(char *str)
{
    int i;
    int err_flag;
    
    i = 0;
    err_flag = 0;
    while (str[i] != 0)
    {
        if (str[0] == '|')
            return (1);
        if ((str[i] == '>' || str[i] == '<' || str[i] == '|'))
        {
            if (!err_flag)
                err_flag = 1;
        }
        else if (err_flag && (!(str[i] == '>' || str[i] == '<' || str[i] == '|' || str[i] == 32)))
            err_flag = 0;
        i++;
    }
    if (err_flag)
        return (1);
    return (0);
}

static int  ft_home_check(char *str, int pos)
{
    if (str[pos] == '~' && str[pos - 1] != '~' && str[pos + 1] != '~' 
        && (str[pos + 1] == '/' || str[pos + 1] == 0 || str[pos + 1] == 32) 
        && (str[pos - 1] == 32 || str[pos - 1] == 0))
        return (1);
    return (0);
}

static int  ft_is_exit(char *str)
{
    if (!(strncmp(str, "$?", 2)))
        return (1);
    else
        return (0);
}

static void    prompt_expander(char **buf, t_env *env)
{
	unsigned char	quote_type;
    char            dump[4096];
    int             i;
    int             j;
    
	i = 0;
    j = 0;
	quote_type = 0;
    bzero(dump, 4096);
    ft_memcpy(dump, *buf, ft_strlen(*buf));
	while (*(dump + i) && j < 4096)
	{
		if ((dump[i] == '\"' || dump[i]== '\'') && (dump[i] != quote_type ) && !quote_type)
			quote_type = dump[i];
		else if (dump[i] == quote_type)
			quote_type = 0;
        if (ft_is_exit(dump + i) && quote_type != '\'')
        {
            ft_memcpy(*(buf) + j, ft_itoa(g_exit), ft_strlen(ft_itoa(g_exit)));
            j += ft_strlen(ft_itoa(g_exit));
        }
        else if (ft_home_check(dump, (i)) && !quote_type)
        {
                ft_memcpy(*(buf) + j, ft_expand(env, "HOME"), ft_strlen(ft_expand(env, "HOME")) + 1);
                i++;
                j += ft_strlen(ft_expand(env, "HOME"));
        }
        if (dump[i] == '$' && quote_type != '\'')
        {
            if (ft_expand(env, dump + i + 1) != NULL)  // if var exist
                ft_memcpy(*(buf) + j, ft_expand(env, dump + i + 1), ft_strlen(ft_expand(env, dump + i + 1)) + 1);
            if (!ft_var_name_stop(dump + i + 1) && dump[i] != '~')
                ft_memcpy(*buf + (++j - 1), dump + (i), 1);
            j += ft_strlen(ft_expand(env, dump + i + 1));  // moving forward in BUF after added variable              
            i += ft_var_name_stop(dump + i + 1) + 1;
            continue ;
        }
        ft_memcpy(*buf + (++j - 1), dump + (++i - 1), 1);
	}
    buf[0][j] = 0;

}

int ft_prompt_parser(char **buf, t_env *env)
{
    if (ft_quote_checker(*buf))
    {
        perror("minishell: open quotes\n");
        return (124);
    }
    if (ft_syntax_checker(*buf))
        return (128);    
    if (ft_strlen(*buf) > 4096)
    {
        printf("too long prompt\n");
        return (1);
    }
    prompt_expander(buf, env);
    if (ft_strlen(*buf) > 4096)
    {
        printf("too long prompt\n");
        return (1);
    }
    return (0);
}
