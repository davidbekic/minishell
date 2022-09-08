#include "../../../includes/minishell.h"

int main(int ac, char **av, char **env)
{
  t_env *env_list;
  t_env *aux;
  int   i;

  i = 0;
  char *str;
  str = malloc(2000);
  env_list = NULL;
  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);
  env_list = ft_init_env(env);
  ft_env(env_list);
  free_env(env_list);
  

  //ft_init_env(env);
}
