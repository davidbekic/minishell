#include "../../../../includes/minishell.h"

int main(int ac, char **av, char **env)
{
  t_env *env_list;
  t_env *aux;
  int   i;

  i = 0;

  char *new_str_to_export = "C00LV4RIABLE=V4RIABLEC00L";
  char *existing_str_to_export = "USER=OBAMA";
  env_list = NULL;
  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);

  env_list = ft_init_env(env);
  //ft_export(ft_find_key(new_str_to_export), ft_find_value(new_str_to_export), env_list);
  //ft_export(ft_find_key(existing_str_to_export), ft_find_value(existing_str_to_export), env_list);
  //ft_unset(env_list, "SHELL");
  //ft_unset(env_list, "TERM_PROGRAM");
  //ft_export("kuksug=haha", env_list);
  env_list = ft_unset("USER2", env_list);
  // env_list = ft_unset(env_list, "TERM_PROGRAM");
  // env_list = ft_unset(env_list, "TERM");
  // env_list = ft_unset(env_list, "_");
  // env_list = ft_unset(env_list, "SHELL");
  // env_list = ft_unset(env_list, "HOME");
  // env_list = ft_unset(env_list, "COLORFGBG");
  // env_list = ft_unset(env_list, "kuksug");
  //printf("env_list in MAIN pointing to: %s\n", env_list->key);
  ft_env(env_list);
  ft_free_env(env_list);
  

  //ft_init_env(env);
}
