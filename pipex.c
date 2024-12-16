/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:13:47 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/16 15:17:55 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	liberte(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char **command;
	char *path;

	command = ft_split(argv, ' ');
	path = find(command[0],envp);
	if (path == 0)//burayı incele/değiştirmen gerekebilir
	{
		liberte(command);
		error();
	}
	if (execve(path,command,envp) == -1)
		error();
}


void child(char **argv,char **envp, int *fd)
{
	int	infile;
	infile = open(argv[1],O_RDONLY,0777);
	if(infile < 0)
		error();
		
	dup2(infile,STDIN_FILENO);
	dup2(fd[1],STDOUT_FILENO);
	close(fd[0]); //pipe'ın fd[0] ucunu kullanmayacağımdan dolayı kapatıyorum.
	execute(argv[2],envp);

}

void parent(char **argv, char **envp, int *fd)
{
	int outfile;
	outfile = open(argv[4], O_RDONLY, 0777);
	
	if(outfile < 0)
		error();
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);//2.prosesten 1.prosese veri aktarımı olmayacağından dolayı pipe'ın parent ucunu kapatıyorum.
	execute(argv[3],envp);
}






int main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid;
	
	if (argc == 5)
	{
		if(pipe(fd) == -1)
			error();
		pid = fork();
		if(pid == 0)
		{	
			child(argv,envp,fd);	
		}
		waitpid(pid,NULL,0);
		parent(argv,envp,fd);
	}	
		
	else
	{
		ft_putstr_fd("Error: Bad Arguments\n",0);
		ft_putstr_fd("E.g. <file1> <cmd1> <cmd2> <file2> \n",0);
	}

}