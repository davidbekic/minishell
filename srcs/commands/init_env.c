#include "../../includes/minishell.h"

typedef struct s_env
{
  char          *key;
  char          *value;
  struct s_env  *next;
}     t_env;

void ft_init_env(char **main_env)
{
  t_env *head;
  int   i;

  head = (t_env *) calloc(sizeof(env_list), 0);
  if (env_list == NULL)
    exit (0);
  i = 0;
  while (main_env[i++] != NULL)
    create_element()


}


int main(int ac, char **av, char **env)
{
  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);
  ft_init_env(env);
}
