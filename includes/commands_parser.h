/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 00:09:50 by gtandeo           #+#    #+#             */
/*   Updated: 2016/10/01 00:09:51 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_PARSER_H
# define COMMANDS_PARSER_H

# include <libft.h>

typedef struct			s_commands
{
	char				*command;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_commands;

t_commands	*get_commands(const char *command_line);

#endif
