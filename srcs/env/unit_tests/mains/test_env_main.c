#include "../../../../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    int i;

    i = 0;
    while (env[i] != NULL)
        printf("%s\n", env[i++]);
}