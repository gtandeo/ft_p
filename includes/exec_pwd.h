/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:36:31 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:36:32 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PWD_H
# define EXEC_PWD_H

# include <libft.h>

# include <unistd.h>
# include <sys/wait.h>

void	exec_pwd(int cs, char **command);

#endif
