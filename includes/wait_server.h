/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_server.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:35:57 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:35:59 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAIT_SERVER_H
# define WAIT_SERVER_H

# include <libft.h>

# include <fcntl.h>

void	wait_server(int sock, char *command);
int		wait_server_pass(int sock);
char	*get_file_name(char *command);

#endif
