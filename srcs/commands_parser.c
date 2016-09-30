/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 00:10:25 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/01 00:10:49 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands_parser.h>

static t_commands	*create_elm(const char *command_part)
{
	t_commands	*elm;

	elm = NULL;
	if ((elm = (t_commands *)malloc(sizeof(t_commands))) != NULL)
	{
		elm->command = ft_strdup(command_part);
		elm->next = NULL;
		elm->prev = NULL;
	}
	return (elm);
}

static t_commands	*add_command(t_commands *lst, t_commands *elm)
{
	t_commands	*tmp;

	if (!lst)
		return (elm);
	tmp = lst;
	if (elm)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = elm;
		elm->prev = tmp;
	}
	return (lst);
}

t_commands			*get_commands(const char *command_line)
{
	t_commands	*list;
	char		**tab;
	size_t		i;

	list = NULL;
	if ((tab = ft_strsplit(command_line, ' ')) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_tablen(tab))
	{
		list = add_command(list, create_elm(tab[i]));
		i++;
	}
	return (list);
}
