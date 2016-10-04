#include <wait_server.h>

/*static void	wait_get(int sock)
{
	(void)sock;
}

static void	wait_set(int sock)
{
	(void)sock;
}*/

static void	wait_other(int sock)
{
	char	*line;

	while (get_next_line(sock, &line) > 0 && ft_strcmp(line, "\033"))
	{
		ft_putendl(line);
		free(line);
	}
}

void		wait_server(int sock, char *command)
{
	(void)command;
	/*if (!ft_strncmp(command, "get", 3))
		wait_get(sock);
	else if (!ft_strncmp(command, "set", 3))
		wait_set(sock);
	else*/
		wait_other(sock);
}