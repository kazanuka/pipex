/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:35:40 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/17 15:13:27 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*adress;

	adress = malloc(ft_strlen(s1)+1);
	if (adress == NULL)
		return (NULL);
	ft_memcpy(adress, s1, ft_strlen(s1) + 1);
	return (adress);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	const char		*firstc;
	char			*address;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	firstc = &s[start];
	address = (char *)malloc(len + 1);
	if (address == NULL)
		return (NULL);
	ft_memcpy(address, firstc, len);
	address[len] = '\0';
	return (address);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	if (!dest && !src)
		return (NULL);
	p = (unsigned char *) src;
	q = (unsigned char *) dest;
	while (n--)
	{
		q[n] = p[n];
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
