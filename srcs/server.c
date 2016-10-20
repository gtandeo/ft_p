/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 09:46:39 by gtandeo           #+#    #+#             */
/*   Updated: 2016/08/11 10:38:40 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <connexion.h>

static void	usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <port>");
	exit(-1);
}

static int	create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Socket error");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

void		parse_command(t_server serv)
{
	char	**command_list;

	if ((command_list = ft_strsplit_whitespace(serv.line)) != NULL)
	{
		if (!ft_strcmp(command_list[0], "ls"))
			exec_ls(serv.cs, command_list);
		else if (!ft_strcmp(command_list[0], "cd"))
			ft_putendl("cd");
		else if (!ft_strcmp(command_list[0], "put"))
			exec_put(serv.cs, command_list);
		else if (!ft_strcmp(command_list[0], "get"))
			exec_get(serv.cs, command_list);
		else if (!ft_strcmp(command_list[0], "pwd"))
			exec_pwd(serv.cs, command_list);
		else
		{
			ft_putstr_fd("ft_p: command not found: ", serv.cs);
			ft_putendl_fd(command_list[0], serv.cs);
		}
	}
	ft_free_tab(command_list);
	ft_putendl_fd("\033", serv.cs);
}

void		run_server(t_server serv)
{
	if (serv.data_list)
		wait_client_login(serv);
	while (get_next_line(serv.cs, &(serv.line)) > 0)
	{
		parse_command(serv);
		free(serv.line);
	}
	return ;
}

int			main(int ac, char **av)
{
	t_server			serv;
	int					port;
	int					sock;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	serv.data_list = get_connexion_data();
	sock = create_server(port);
	serv.cs = accept(sock, (struct sockaddr*)&csin, &cslen);
	run_server(serv);
	delete_connexion_data(serv.data_list);
	close(serv.cs);
	close(sock);
	return (0);
}
