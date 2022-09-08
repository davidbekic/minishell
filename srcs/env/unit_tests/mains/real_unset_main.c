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
  ft_unset(env_list, "TERM_PROGRAM");
  ft_env(env_list);
  free_env(env_list);
  

  //ft_init_env(env);
}
