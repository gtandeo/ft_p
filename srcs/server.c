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

static void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
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
		printf("Socket error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

/*void		parse_command(t_server serv)
{
	return ;
}*/

void		run_server(t_server serv)
{
	while (get_next_line(serv.cs, &(serv.line)))
	{
		printf("recieved %zu bytes: [%s]\n", ft_strlen(serv.line), serv.line);
		//parse_command(serv);
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
	printf("%s\n", serv.data_list->login);
	sock = create_server(port);
	serv.cs = accept(sock, (struct sockaddr*)&csin, &cslen);
	run_server(serv);
	delete_connexion_data(serv.data_list);
	close(serv.cs);
	close(sock);
	return (0);
}
