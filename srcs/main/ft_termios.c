/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:39:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/26 11:45:33 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_termios_child(void)
{
	struct termios	term;
	struct termios	save_termios;

	if (isatty(STDIN_FILENO) == 0)
		ft_error("this fd is not a tty", 130);
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		ft_error("get attributes error", 130);
	save_termios = term;
	term.c_lflag |= (ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) < 0)
		ft_error("set attributes error", 130);
	if (term.c_lflag == (ECHOCTL))
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &save_termios);
		ft_error("attributes wrongly set", 130);
	}
}
