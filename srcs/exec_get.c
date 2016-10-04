#include <exec_get.h>

void	exec_get(int cs, char **command)
{
	if (!command[1])
	{
		ft_putendl_fd("usage: get [file]", cs);
		return ;
	}
}
