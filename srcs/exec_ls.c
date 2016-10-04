#include <exec_ls.h>

void	exec_ls(t_server serv, char **command)
{
	(void)serv;
	execv("/bin/ls", command);
	ft_putendl("ls");
	return ;
}
