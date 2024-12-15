/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:13:47 by fkuyumcu          #+#    #+#             */
/*   Updated: 2024/12/15 15:36:28 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find(char *cmd, char **envp)
{
	
}

void liberation(char **)

void	execute(char *argv, char **envp)
{
	char **command;
	int i;
	char *path;

	i = -1;
	command = ft_split(argv, ' ');
	path = find(command[0],envp);
	if (path == 0)//burayı incele/değiştirmen gerekebilir
	{
		while (command[++i])
			free(command[i]);
		free(command);
		error();
	}
	if (execve(path,argv,envp) == -1)
		error;
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



void error(void)
{
	perror("An error occured.");
	exit(EXIT_FAILURE);
}


void main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid;
	
	if (argc == 5)
	{
		if(pipe(fd) == -1)
			return ("error");
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
		ft_printf("Error: Bad Arguments\n");
		ft_printf("E.g. <file1> <cmd1> <cmd2> <file2> \n");
	}

}