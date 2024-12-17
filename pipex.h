/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:59:48 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/17 15:19:18 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

# define ERR_INFILE "Infile Error"
# define ERR_OUTFILE "Outfile Error"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe error"
# define ERR_PATH "Path not found\n"
# define ERR_CMD "Command not found\n"
# define ERR_PRC "The process failed\n"

void	error(char *error);
char	*find(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	liberte(char **slave);
int		is_there_path(char *envp[]);

char	*ft_strjoin(char const *s1, char const *s2);
int		count_tokens(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);

#endif