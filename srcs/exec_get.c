#include <exec_get.h>

void	exec_get(int cs, char **command)
{
	int		file;
	char	*line;

	if (!command[1])
	{
		ft_putendl_fd("usage: get [file]", cs);
		return ;
	}
	if ((file = open(command[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("get: ", cs);
		ft_putstr_fd(command[1], cs);
		ft_putendl_fd(": cant open file", cs);
		return ;
	}
	while (get_next_line(file, &line) > 0)
	{
		ft_putendl_fd(line, cs);
		free(line);
	}
	close(file);
}
