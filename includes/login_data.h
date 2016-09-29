/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   login_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:57:29 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/29 21:57:30 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIN_DATA_H
# define LOGIN_DATA_H

# define LOGIN_DATA_PATH "data/connexion_data.dat"

# include <libft.h>

# include <fcntl.h>

typedef struct			s_login_data
{
	int					used;
	char				*login;
	char				*psswd;
	struct s_login_data	*next;
	struct s_login_data	*prev;
}						t_login_data;

t_login_data			*get_connexion_data(void);
void					delete_connexion_data(t_login_data *data);

#endif
