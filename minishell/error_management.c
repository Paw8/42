/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:50 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/09 20:22:12 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_errors(t_command *command, int errnum, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	if (errnum == 256)
		too_many_args(command, str);
	else if (errnum == 257)
		numeric_needed(command, str);
	else if (errnum == 258)
		syntax_error(command, str);
	else if (errnum == 259)
		cmd_not_found(command);
	else if (errnum == 260)
		not_valid_identifier(command, str);
	else if (errnum == 261)
		cd_no_such(command, str);
	else
		some_other_error(command, errnum, str);
	return (-1);
}

void	syntax_error(t_command *command, char *str)
{
	ft_putstr_fd("syntax error near unexpected token `", 2);
	if (str && str[0] == '\0')
		ft_putstr_fd("newline", 2);
	else
		ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
	command->errnum = 2;
}

void	some_other_error(t_command *command, int errnum, char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(strerror(errnum), 2);
	ft_putstr_fd("\n", 2);
	command->errnum = errnum;
}

void	cmd_not_found(t_command *command)
{
	ft_putstr_fd(command->splited_str[0], 2);
	if (ft_strchr(command->splited_str[0], '/'))
	{
		ft_putstr_fd(": no such file or directory\n", 2);
		command->errnum = 1;
	}
	else
	{
		ft_putstr_fd(": command not found\n", 2);
		command->errnum = 127;
	}
}

void	numeric_needed(t_command *command, char *str)
{
	ft_putstr_fd(command->splited_str[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	command->errnum = 22;
}
