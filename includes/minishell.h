/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/20 18:27:22 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define MAXARGS 10
# define RWRR (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define WCA O_WRONLY | O_CREAT | O_APPEND
# define RDCE O_RDWR | O_CREAT | O_EXCL
# define BUFFER_SIZE 4096

typedef	struct s_env
{
  char            *key;
  char            *value;
  char            **envp;
  int             lst_len;
  struct s_env    *next;
}     t_env;

typedef	struct cmd
{
	int type;
}	cmd;

typedef	struct doexec
{
	int		  type;
	char	*names[10];
	char	*end_names[10];
}	doexec;

typedef	struct  doredir
{
	int			type;
	struct cmd	*cmd;
	char		*file;
	char		*efile;
	int			right;
	int			fd;
}	doredir;

typedef	struct dopipe
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
struct cmd	*terminate(struct cmd *cmd);
struct cmd	*builtexec(char **pstr, char *estr);
struct cmd	*builtparse(char *str);
int			ft_quotes_simple(char **pstr, char *estr, char **ftoken, char **eftoken);
void		ft_runcmd(struct cmd *cmd, t_env *env);
int			ft_prompt_parser(char **buf, t_env *env);
int			ft_setcmd(struct doexec **cmd, char *ftoken, char *eftoken, int sign);
int			ft_quotes(char **pstr, char *estr, char **ftoken, char **eftoken);
int			ft_is_builtin(char *buf);
void		ft_redir_exec(struct cmd *cmd);
void	ft_simple_redir(struct cmd *cmd, char *array[2], char file[20], int operator);
void	p_struct(struct cmd *cmd, struct cmd *srcmd[]);
void	ft_prompt_expander(char **buf, t_env *env);

//Building tree structs
struct cmd	*buildexec(void);
struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile, int right, int fd);
struct cmd	*buildpipe(struct cmd *left, struct cmd *right);
//Utils
void		ft_error(char *str, int exit_code);
int			fork1(void);
int			ft_find(char **pstr, char *estr, char *tokens);
int			gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
void		ft_heredoc(struct cmd *cmd, t_env *env);

//Env
t_env   *ft_init_env(char **main_env);
t_env   *ft_create_elem(t_env *new, char *key_value, int value_start);
int		ft_envsize(t_env *env);
char	**ft_create_envp(t_env *env);
//t_env   *ft_create_elem(t_env *new, char *env_variable);
t_env   *ft_find_elem(t_env *env, char *key);
t_env   *ft_find_elem_before(t_env *env, char *key);
int	ft_find_key(char *pattern);
int	ft_find_value(char *pattern);
char    *ft_expand(t_env *env, char *key);
void    ft_free_env(t_env *env, int err);
void	ft_free_envp(char **envp);
//void    ft_update_var(char *key, char *value, t_env *list);
void	ft_alphabetic_env(t_env *env);
int	ft_var_name_check(char *str, int len);
int	ft_var_name_stop(char *str);
int	ft_update_var(char *key_value, int value_start, t_env *env);

// exec
int		ft_run_builtin(t_env *env, char **buf);
int		ft_execve(t_env *env, char **names);
int 	ft_find_command(struct doexec *cmd, t_env *env);
void	ft_word_to_lower(char *command);
int 	ft_is_file_or_dir(char *str);
int		ft_is_file(const char *path);

// signals
void		ft_info_handler(int signo, siginfo_t *info, void *context);
void		ft_handler(int signo);
void		ft_signals(void);
void	ft_termios(void);

//Built-ins
int			ft_env(t_env *env, char **names);
int			ft_export(char **names, t_env *env);
int			ft_pwd(t_env *env);
int			ft_echo(char **names);
int			ft_unset(char **names, t_env **env);
int			ft_cd(t_env *env, char **names);
void		ft_exit(char **names);

#endif
