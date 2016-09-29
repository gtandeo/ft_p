/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_login_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:56:22 by gtandeo           #+#    #+#             */
/*   Updated: 2016/09/29 21:56:23 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <login_data.h>

static t_login_data	*create_login_node(const char *login, const char *psswd)
{
	t_login_data	*elm;

	if ((elm = (t_login_data *)malloc(sizeof(t_login_data))) != NULL)
	{
		elm->login = ft_strdup(login);
		elm->psswd = ft_strdup(psswd);
		elm->next = NULL;
		elm->prev = NULL;
		return (elm);
	}
	return (NULL);
}

static t_login_data	*add_login_node(t_login_data *list, t_login_data *elm)
{
	t_login_data	*tmp;

	if (!list)
		return (elm);
	tmp = list;
	if (elm)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = elm;
		elm->prev = tmp;
	}
	return (list);
}

t_login_data		*get_connexion_data(void)
{
	int				fd;
	char			*line;
	char			**tmp;
	t_login_data	*list;

	if ((fd = open(LOGIN_DATA_PATH, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Unable to open specified data file.", 2);
		return (NULL);
	}
	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ':');
		list = add_login_node(list, create_login_node(tmp[0], tmp[1]));
		ft_free_tab(tmp);
		free(line);
	}
	return (list);
}

void				delete_connexion_data(t_login_data *list)
{
	if (list->next)
		delete_connexion_data(list->next);
	free(list->login);
	free(list->psswd);
	free(list);
	return ;
}
