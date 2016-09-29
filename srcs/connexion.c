/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 00:58:25 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/30 00:58:26 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <connexion.h>

static int	find_login(t_login_data *list, const char *client_login, char **client_psswd)
{
	t_login_data	*tmp;

	if (list)
	{
		tmp = list;
		while (tmp && tmp->next)
		{
			if (!ft_strcmp(tmp->login, client_login))
			{
				*client_psswd = ft_strdup(tmp->psswd);
				return (0);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}

void		wait_client_psswd(t_server serv)
{
	ft_putendl_fd("password:", serv.cs);
	ft_putendl_fd("WAIT", serv.cs);
	while (get_next_line(serv.cs, &(serv.line)) > 0 && ft_strcmp(serv.line, serv.psswd))						//wait client password
	{
		ft_putendl_fd("Connexion error: incorrect password", serv.cs);
		ft_putendl_fd("password: ", serv.cs);
		ft_putendl_fd("WAIT", serv.cs);
		free(serv.line);
	}
	ft_putendl_fd("psswd_ok", serv.cs);
	free(serv.line);
	ft_putendl("end");
}

void		wait_client_login(t_server serv)
{
	while (ft_strcmp(serv.line, "connect"))			//wait client connexion request
	{
		if (serv.line)
			free(serv.line);
		get_next_line(serv.cs, &(serv.line));
		ft_putendl(serv.line);
	}
	ft_putendl_fd("login: ", serv.cs);
	ft_putendl_fd("WAIT", serv.cs);
	while (get_next_line(serv.cs, &(serv.line)) > 0 && find_login(serv.data_list, serv.line, &(serv.psswd)))	//wait client login
	{
		ft_putendl_fd("Connexion error: bad login", serv.cs);
		ft_putendl_fd("login: ", serv.cs);
		ft_putendl_fd("WAIT", serv.cs);
		free(serv.line);
	}
	ft_putendl_fd("login_ok", serv.cs);
	serv.login = ft_strdup(serv.line);
	free(serv.line);
	wait_client_psswd(serv);
}
