/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 01:19:50 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/27 01:19:51 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <login_data.h>
# include <exec_ls.h>
# include <exec_pwd.h>
# include <exec_get.h>

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct			s_server
{
	int					cs;
	char				*login;
	char				*psswd;
	char				*line;
	struct s_login_data	*data_list;
}						t_server;

#endif
