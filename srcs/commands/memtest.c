#include "../../includes/minishell.h"

int main(void)
{
	char str[100] = "hello";
	printf("strlen(str): %zu\n", strlen(str));
	printf("%s\n", memcpy(str + strlen(str) - 1, "there", 3));
}

