/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/09 13:32:03 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

typedef struct s_env
{
  char          *key;
  char          *value;
  struct s_env  *next;
}     t_env;

t_env   *ft_init_env(char **main_env);
t_env   *ft_create_elem(t_env *new, char *key, char *value);
//t_env   *ft_create_elem(t_env *new, char *env_variable);
t_env   *ft_find_elem(t_env *env_list, char *key);
t_env   *ft_find_elem_before(t_env *env_list, char *key);
char    *ft_find_key(char *pattern);
char    *ft_find_value(char *pattern);
char    *ft_expand(t_env *env_list, char *key);
void    free_env(t_env *env_list);
void    ft_env(t_env *env_list);
void    ft_update_var(char *key, char *value, t_env *list);
void    ft_export(char *key, char *value, t_env *list);
t_env   *ft_unset(t_env *env_list, char *key);



#endif

