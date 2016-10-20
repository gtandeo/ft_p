/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:37:46 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:37:46 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec_ls.h>

void	exec_ls(int cs, char **command)
{
	pid_t	i;

	i = fork();
	if (i == 0)
	{
		dup2(cs, 1);
		execv("/bin/ls", command);
	}
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
	{
		ft_putendl("fork error");
		return ;
	}
	ft_putendl_fd("SUCCESS", cs);
	return ;
}
