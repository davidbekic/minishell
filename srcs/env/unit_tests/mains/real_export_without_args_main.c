#include "../../../../includes/minishell.h"

int main(int ac, char **av, char **env)
{
  t_env *env_list;
  int   i;

  i = 0;

//  char *new_str_to_export = "C00LV4RIABLE=V4RIABLEC00L YO YO YO";
  char *new_str_to_export = NULL;
  printf("new str to export: %s\n", new_str_to_export);
  env_list = NULL;
  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);
  env_list = ft_init_env(env);
  ft_export(new_str_to_export, env_list);
  free_env(env_list);
  

  //ft_init_env(env);
}
