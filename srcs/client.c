/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 09:46:39 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/27 01:11:15 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	usage(char *str)
{
	printf("Usage: %s <arrd> <port>\n", str);
	exit(-1);
}

int		create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(2);
	}
	return (sock);
}

void	get_connexion_request(int sock)
{
	char	*line;
	char	*server_line;

	while (get_next_line(sock, &server_line) > 0 && ft_strcmp(server_line, "login_ok"))
	{
		if (!ft_strcmp(server_line, "WAIT"))
		{
			get_next_line(0, &line);
			ft_putendl_fd(line, sock);
			free(line);
		}
		else
			ft_putendl(server_line);
		free(server_line);
	}
	while (get_next_line(sock, &server_line) > 0 && ft_strcmp(server_line, "psswd_ok"))
	{
		if (!ft_strcmp(server_line, "WAIT"))
		{
			get_next_line(0, &line);
			ft_putendl_fd(line, sock);
		}
		else
			ft_putendl(server_line);
		free(server_line);
	}
}

int		main(int ac, char **av)
{
	int		port;
	int		sock;
	char	*line;

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putendl_fd("connect", sock);
	get_connexion_request(sock);
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, "quit"))
	{
		ft_putendl_fd(line, sock);
		free(line);
		while (get_next_line(sock, &line) > 0 && ft_strcmp(line, "\033"))
		{
			ft_putendl(line);
			free(line);
		}
	}
	close(sock);
	return (0);
}
