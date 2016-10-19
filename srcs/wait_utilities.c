/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:36:52 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:36:53 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wait_server.h>

char	*get_file_name(char *command)
{
	int		i;

	i = ft_strlen(command) - 1;
	while (i && command[i] != ' ' && command[i] != '/')
		i--;
	return (ft_strdup(command + i + 1));
}

int		wait_server_pass(int sock)
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
