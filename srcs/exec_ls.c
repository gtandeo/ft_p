#include <exec_ls.h>

void	exec_ls(t_server serv, char **command)
{
	pid_t	i;

	i = fork();
	(void)serv;
	if (i == 0)
		execv("/bin/ls", command);
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
		ft_putendl("fork error");
	return ;
}
