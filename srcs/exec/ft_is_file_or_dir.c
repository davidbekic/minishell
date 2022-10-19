/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file_or_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:24:20 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/19 17:41:27 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_is_file(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

static int	ft_is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int	ft_is_file_or_dir(char *str)
{
	if (!ft_is_directory(str) && !ft_is_file(str))
	{
		ft_printf(2, "minishell: %s: No such file or directory\n", str);
		return (127);
	}
	else if (ft_is_directory(str))
	{
		ft_printf(2, "minishell: %s: is a directory\n", str);
		return (126);
	}
	return (0);
}
