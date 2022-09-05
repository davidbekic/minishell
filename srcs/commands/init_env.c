#include "../../includes/minishell.h"

typedef struct s_env
{
  char          *key;
  char          *value;
  struct s_env  *next;
}     t_env;

void  find_key(char *key, char *env_variable)
{
  int   i;

  i = 0;
  while (env_variable[i] != '=')
    i++;
  key = calloc(i + 1, 0);
  i = 0;
  while (env_variable[i] != '=')
  {
    key[i] = env_variable[i];
    //printf("env_variable[%d]: %c\n", i, env_variable[i]);
    i++;
  }
  key[i] = 0;
}

void  find_value(char *value, char *env_variable)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (env_variable[i] != '=')
    i++;
  i++;
  value = calloc(strlen(env_variable + i) + 1, 1);
  while (env_variable[i] != 0)
  {
    value[j] = env_variable[i];
    printf("env_variable[%d]: %c\n", i, env_variable[i]);
    i++;
    j++;
  }
  value[j] = 0;
}

void  find_key_value(char *key, char *value, char *env_variable)
{
  find_key(key, env_variable);
  find_value(value, env_variable);
}

t_env *ft_create_element(t_env *new, char *key, char *value)
{
  new = (t_env *) calloc(sizeof(t_env), 1);
  if (new == NULL)
    return (NULL);
  new->key = (char *) calloc(strlen(key) + 1, 1);
  if (new->key == NULL)
    return (NULL);
  new->key = key;
  new->value = (char *) calloc(strlen(value) + 1, 1);
  if (new->value == NULL)
    return (NULL);
  new->value = value;
  new->next = NULL;
  return (new);
}

t_env *ft_init_env(char **main_env)
{
  t_env *head;
  t_env *current;
  t_env *temp;
  char  *key;
  char  *value;
  int   i;

  head = (t_env *) calloc(sizeof(t_env *), 1);
  if (head == NULL)
    return (NULL);
  find_key_value(key, value, main_env[0]);
  printf("key: %s\n", key);
  head = ft_create_element(head, key, value);
  temp = head;
  i = 0;
  while (main_env[i] != NULL)
  {
    current = ft_create_element(current, "KUK", "VALUE");
    temp->next = current;
    temp = current;
    i++;
  }
  return (head);
}

int main(int ac, char **av, char **env)
{
  t_env *env_list;

  env_list = NULL;
  if (ac == 0)
    exit(0);
  if (av == NULL)
    exit(0);
  env_list = ft_init_env(env);
  while (env_list->next != NULL)
  {
    printf("%s | %s\n", env_list->key, env_list->value);
    env_list = env_list->next;
  }
}
