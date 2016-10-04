#include <exec_ls.h>

static void	read_ls(int cs)
{
	char	*line;

	while (get_next_line(1, &line))
	{
		ft_putendl_fd(line, cs);
		free(line);
	}
}

void		exec_ls(int cs, char **command)
{
	pid_t	i;

	i = fork();
	(void)cs;
	if (i == 0)
	{
		execv("/bin/ls", command);
		read_ls(cs);
	}
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
		ft_putendl("fork error");
	return ;
}
