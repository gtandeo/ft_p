/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 00:59:07 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/30 00:59:07 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNEXION_H
# define CONNEXION_H

# include <libft.h>
# include <server.h>

void		wait_client_login(t_server serv);
void		wait_client_psswd(t_server serv);

#endif
