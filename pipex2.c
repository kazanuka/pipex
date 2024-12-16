/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:13:32 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/16 15:13:47 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(void)
{
	perror("An error occured.");
	exit(EXIT_FAILURE);
}



void liberte(char **slave)
{
	int i;
	
	i = 0;
	while (slave[i])
			free(slave[i++]);
		free(slave);
}