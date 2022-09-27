//We want to iterate the names** from position 1 or 2 depending on flag or not flag.
//
//We need to handle the following special conditions:
//1. @ inside " ".
//2. Check whether there is quoting going on.
//
//
//Quoting
//We will check quoting by finding the first type of quote to appear in any one of the strings.
//When we do this, we will remember what type of quote it was and enter into an "in_quote"-mode. 
//If or when when find another one of those quotes, we turn off the "in_quote" mode and restart
//the search. 
//
//Bascically, when we're inside "in_quote" mode, we can find any value we want, but if 
//"in_quote" is still on when the iterations are done, we give error message. 
//
//The only thing that can break "in_quote" mode is we find the same value that initialised it.
// If I find a quote, and it's not the type of quote in "quote_type", and "in_quote" is not turned on
// --> I should put quote in buffer.
//
//
// EXPANDER
// When I encounter an @, I need to send the next characters up until invalid $VAR char in
// a string to ft_expand($VAR);
//
// My first basic question is; how do I extract these chars? Can I do it without creating another string?
// Can I do it in a line efficient way?
//
//

#include "../../includes/minishell.h"

char *ft_echo_expand(char *var, t_env *env)
{
	char	str[100];
	char	*retstr;
	int	i;

	i = 0;
	i = ft_non_allowed_char_for_var(var, ft_strlen(var));
	if (i)
		return (NULL);
	printf("var: %s\n", var);
	memcpy(str, var, ft_strlen(var));
	printf("str: %s\n", str);
	retstr = ft_expand(env, str);
	printf("%s\n", retstr);
	return (retstr);
}

unsigned char	ft_echo(char **names, t_env *env)
{
	int		i;
	int		j;
	unsigned char	inside_quote;
	unsigned char	quote_type;
	char		buf[1000];

	i = 0;
	j = 1;
	inside_quote = 0;
	quote_type = 0;
	memset(buf, 0, 1000);
	while (names[j] != NULL)
	{
		while (names[j][i] != 0)
		{
			if (names[j][i] == '$' && (quote_type == '\"' || quote_type == 0))
			{
				printf("haha\n");
				ft_memcpy(buf + ft_strlen(buf), 
				ft_echo_expand(names[j] + ft_strlen(buf) -2, env), 1000);
				i = 0;
				j++;
				ft_memcpy(buf + ft_strlen(buf), " ", 1);
				continue ;
			}
			ft_memcpy(buf + ft_strlen(buf), &names[j][i], 1);
			if (names[j][i] == '\'' || names[j][i] == '\"')		 
			{
				// ENCOUNTER OF CORRECT QUOTE
				if (quote_type == 0 || quote_type == names[j][i])
				{
					quote_type = names[j][i];
					ft_memcpy(buf + ft_strlen(buf) - 1, "\0", 1);
					inside_quote++;
				}
			}
			if ((inside_quote) && (names[j][i] == '\'' || names[j][i] == '\"') && names[j][i] == quote_type)
				ft_memcpy(buf + ft_strlen(buf), "\0", 1);
			if (inside_quote == 2)
				inside_quote = 0;
			i++;
		}
		ft_memcpy(buf + ft_strlen(buf), " ", 1);
		j++;
		i = 0;
	}
	if (!inside_quote)
		printf("OUT: %s\n", buf);
	else
		printf("OPEN QUOTES\n");
	printf("inside quote @ return: %d\n", inside_quote);
	return (inside_quote);
}

// int	main(int ac, char **av, char **main_env)
// {
// 	char		**names;
// 	t_env		*env;
// 	unsigned char		i = 0;

// 	printf("sug min: %d %s\n", ac, av[1]);
// 	env = ft_init_env(main_env);
// 	names = malloc(2000);
// 	names[0] = malloc(2000);
// 	names[1] = malloc(2000);
// 	names[2] = malloc(2000);
// 	names[0] = "echo";
// 	names[1] = "-n";
// 	names[2] = "\" ' \" \'";
// 	names[3] = "there";
// 	names[4] = NULL;
// 	i =	ft_echo(names, env);
// }
