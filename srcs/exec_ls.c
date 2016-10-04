#include <exec_ls.h>

void		exec_ls(int cs, char **command)
{
	pid_t	i;

	i = fork();
	(void)cs;
	if (i == 0)
	{
		dup2(cs, 1);
		execv("/bin/ls", command);
	}
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
		ft_putendl("fork error");
	return ;
}
