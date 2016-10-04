#include <wait_server.h>

static char	*get_file_name(char *command)
{
	int		i;

	i = ft_strlen(command) - 1;
	while (i && command[i] != ' ' && command[i] != '/')
		i--;
	return (ft_strdup(command + i + 1));
}

static int	wait_server_pass(int sock)
{
	char	*line;

	while (get_next_line(sock, &line) > 0 && ft_strcmp(line, "\033"))
	{
		if (!ft_strcmp(line, "get_ok"))
		{
			free(line);
			return (0);
		}
		ft_putendl(line);
		free(line);
	}
	return (1);
}

static void	wait_get(int sock, char *command)
{
	char	*line;
	char	*file_name;
	int		fd;

	if (wait_server_pass(sock))
		return ;
	file_name = get_file_name(command);
	if ((fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)) == -1)
		return ;
	while (get_next_line(sock, &line) > 0 && ft_strcmp(line, "\033"))
	{
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(file_name);
	close(fd);
}

static void	wait_set(int sock)
{
	(void)sock;
}

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
	if (!ft_strncmp(command, "get", 3))
		wait_get(sock, command);
	else if (!ft_strncmp(command, "set", 3))
		wait_set(sock);
	else
		wait_other(sock);
}