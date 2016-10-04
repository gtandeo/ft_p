#include <exec_pwd.h>

void	exec_pwd(int cs, char **command)
{
	pid_t	i;

	i = fork();
	if (i == 0)
	{
		dup2(cs, 1);
		execv("/bin/pwd", command);
	}
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
		ft_putendl("fork error");
	return ;
}
