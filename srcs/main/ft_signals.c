/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 22:01:25 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>
#include <termios.h>

extern int g_exit;

void	ft_termios(void)
{
	struct termios	term;

	if (isatty(STDIN_FILENO) == 0)
		ft_error("this fd is not a tty", 130);
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		ft_error("get attributes error", 130);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) < 0)
		ft_error("set attributes error", 130);
	if (term.c_lflag & (ECHOCTL))
		ft_error("attributes wrongly set", 130);
}

void	ft_signals(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	act.sa_handler = SIG_IGN;
//	act.sa_mask = 0;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART | SA_SIGINFO;
	act.sa_sigaction = ft_info_handler;
	if (sigaction(SIGCHLD, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGINT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	signal(SIGSEGV, ft_ssh);
}

void	ft_handler(int signo)
{
	printf("chield died with signo:%d\n", signo);
}

void	ft_info_handler(int signo, siginfo_t *info, void *context)
{
	int	child;
	static int status;

	(void)context;
	child = info->si_pid;
	// if (info->si_status)
	status = info->si_status;
	if (g_exit < 256)
		g_exit = status;
	// printf("status: %d\n", info->si_status);
	// printf("signo: %d AND SIGCHLD: %d\n", signo, SIGCHLD);
	if (signo == SIGCHLD)
	{
		//printf("child died\n");
	}
	if (signo == SIGINT)
	{
		
		//printf("sigint %s\n", rl_line_buffer);
		//if (ioctl(STDIN_FILENO, TIOCSTI, "\n") < 0)
		//	ft_error("ioctl erro", 130);
		//printf("state %lu\n", rl_readline_state);
		//write(2, "\n", 1);
		g_exit = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		//if (RL_STATE_REDISPLAYING)
		//	printf("true\n");
	}
}
