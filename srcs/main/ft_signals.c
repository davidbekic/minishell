/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 14:25:48 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>
#include <termios.h>

void	ft_signals(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	act.sa_handler = SIG_DFL;
//	act.sa_mask = 0;
	ft_memset(&act, 0, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART | SA_SIGINFO; //| SA_NOCLDWAIT;
	act.sa_sigaction = ft_info_handler;
	if (sigaction(SIGINT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGQUIT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR1, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR2, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGTTOU, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGTTIN, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	signal(SIGUSR3, ft_ssh);
	signal(SIGUSR4, ft_ssh);
}

// void	ft_handler(int signo, siginfo_t *info, void *context)
// {
// 	printf("entro en handler\n");
// 	if (signo == SIGINT)
// 	{
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	(void)context;
// 	(void)info;
// 	printf("chield died with signo:%d\n", signo);
// }

void	ft_info_handler(int signo, siginfo_t *info, void *context)
{
//	int	child;
	static int	state;
	int	status;
//	int	signo2;
//	pid_t	pid;

	(void)context;

//	(void)info;
	//printf("entro en info handler\n");
//	child = info->si_pid;
	status = info->si_status;
	//g_exit = status;
	// printf("status: %d\n", status);
//	signo2 = info->si_signo;
//	pid = info->si_pid;
//	printf("pid: %d status: %d y signo: %d, pid info: %d\n", child, status,	signo2, pid);
//	printf("signo %d\n", signo2);
	if (signo == SIGTTOU)
		printf("hola\n");
	if (signo == SIGTTIN)
		write(2, "hola\n", 5);
	if (signo == SIGUSR1)
	{
//		printf("estoy en child\n");
		state = 1;
			//	printf("state es %d\n", state);
	}
//	printf("child %d\n", child);
//	printf("state despues es %d\n", state);
	else if (signo == SIGUSR2)
	{
		// printf("entering here?\n");
		state = 0;
	}
//	printf("antes state %d child %d\n", state, child);

	if (state == 0)
	{
		if (signo == SIGINT)
		{
			g_exit = 1;
			write(2, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else if (signo == SIGQUIT)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		
	}
	if (state == 1)
	{
		// printf("SIGNO: %d\n", signo);
		if (signo == SIGQUIT)
		{
			write(2, "Quit: 3\n", 8);
			g_exit = 128 + status;
			// printf("g_exit in SIGQUIT condition: %d\n", g_exit);
			kill(0, SIGINT);
		}
		else if (signo == SIGINT && g_exit != 131)
			g_exit = 128 + status;
		
	/*	else if (signo == SIGINT)
		{
			state = 0;
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
		}*/

	}

}