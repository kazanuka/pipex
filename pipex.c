void pipex(int file1, int file2, char *cmd1, char *cmd2)
{
	int	end[2];
	int	f;
	pipe(end);
	f = fork();
	if (parent == 0)
	{
		child(file1,cmd2);
	}
	else if (parent > 0)
	{
		parent();
	}
	else
		return (perror("An Error Occured.\n")); //error


}


void child(int f1,char *cmd1)
{

}

void parent(int f2, char *cmd2)
{

}