/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:13:32 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/17 15:18:26 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	liberte(char **slave)
{
	int	i;

	i = 0;
	while (slave[i])
		free(slave[i++]);
	free(slave);
}

int	is_there_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			return (1);
		i++;
	}
	return (0);
}
