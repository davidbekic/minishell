#include "../../includes/minishell.h"

typedef struct s_env
{
  char          *key;
  char          *value;
  struct s_env  *next;
}     t_env;


t_env *ft_create_element(t_env *new, char *env_variable)
{
  int i;
  int j;

  i = 0;
  j = 0;
  new = (t_env *) calloc(sizeof(t_env), 1);
  if (new == NULL)
    return (NULL);
  while (env_variable[i] != '=')
    i++;
  new->key = calloc(i + 1, 1);
  i = 0;
  while (env_variable[i] != '=')
  {
    new->key[i] = env_variable[i];
    i++;
  }
  i++;
  new->value = calloc(strlen(env_variable + i) + 1, 1);
  while (env_variable[i] != 0)
  {
    new->value[j] = env_variable[i];
    i++;
    j++;
  }
  new->value[j] = 0;
  new->next = NULL;
  return (new);
}

t_env *ft_init_env(char **main_env)
{
  t_env *head;
  t_env *current;
  t_env *temp;
  int   i;

  head = (t_env *) calloc(sizeof(t_env *), 1);
  if (head == NULL)
    return (NULL);
  head = ft_create_element(head, main_env[0]);
  temp = head;
  i = 1;
  while (main_env[i] != NULL)
  {
    current = ft_create_element(current, main_env[i]);
    temp->next = current;
    temp = current;
    i++;
  }
  return (head);
}

int main(int ac, char **av, char **env)
{
  t_env *env_list;
  int   i;

  i = 0;
  env_list = NULL;

  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);

  env_list = ft_init_env(env);
  while (env_list->next != NULL)
  {
    //printf("%s\n", env[i]);
    //printf("%s\n", env_list->key);
    printf("%s=%s\n", env_list->key, env_list->value);
    env_list = env_list->next;
    i++;
  }
  printf("%s=%s\n", env_list->key, env_list->value);
  ft_init_env(env);
}
