#ifndef WAIT_SERVER_H
# define WAIT_SERVER_H

# include <libft.h>

# include <fcntl.h>

void	wait_server(int sock, char *command);
int		wait_server_pass(int sock);
char	*get_file_name(char *command);

#endif
