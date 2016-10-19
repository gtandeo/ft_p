/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:39:39 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:39:40 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec_pwd.h>

void	exec_pwd(int cs, char **command)
{
	pid_t	i;

	i = fork();
	if (i == 0)
	{
		dup2(cs, 1);
		execv("/bin/pwd", command);
	}
	else if (i > 0)
		wait4(i, 0, 0, NULL);
	else
		ft_putendl("fork error");
	return ;
}
