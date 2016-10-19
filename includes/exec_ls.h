/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:39:51 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/20 00:39:52 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_LS_H
# define EXEC_LS_H

# include <libft.h>

# include <unistd.h>
# include <sys/wait.h>

void	exec_ls(int cs, char **command);

#endif
