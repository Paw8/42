/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:45:04 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/09 20:22:22 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	too_many_args(t_command *command, char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": too many arguments\n", 2);
	command->errnum = 7;
}

void	not_valid_identifier(t_command *command, char *str)
{
	ft_putstr_fd(command->splited_str[0], 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	command->errnum = 1;
}

void	cd_no_such(t_command *command, char *str)
{
	ft_putstr_fd(command->splited_str[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	command->errnum = 1;
}
