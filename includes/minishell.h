/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by dbekic            #+#    #+#             */
/*   Updated: 2022/09/13 15:36:53 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include "../Libft/libft.h"

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define O_WRONLY 10
# define O_CREAT 11
# define O_RDONLY 12

typedef struct s_env
{
  char          *key;
  char          *value;
  struct s_env  *next;
}     t_env;

typedef struct cmd
{
	int	type;
}	cmd;

typedef struct doexec
{
	int		type;
	char	*names[10];
	char	*end_names[10];
}	doexec;

typedef struct doredir
{
	int			type;
	struct cmd	*cmd;
	char		*file;
	char		*efile;
	int			right;
	int			fd;
}	doredir;

typedef struct dopipe
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
}	dopipe;

//Parsing
struct cmd	*parsecmd(char *str);
struct cmd	*parseline(char **pstr, char *estr);
struct cmd	*parsepipe(char **pstr, char *estr);
struct cmd	*parseredirs(char **pstr, char *estr, struct cmd *cmd);
struct cmd	*parseexec(char **pstr, char *estr);
void		ft_runcmd(struct cmd *cmd);
//Building tree structs
struct cmd	*buildexec(void);
struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile, int right, int fd);
struct cmd	*buildpipe(struct cmd *left, struct cmd *right);
//Utils
void	ft_error(char *str);
int		fork1(void);
int		ft_find(char **pstr, char *estr, char *tokens);
int		gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);

//Env
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

// exec
void	ft_execve(t_env *env, char **names);


#endif

