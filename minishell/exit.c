/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:19:14 by mokatova          #+#    #+#             */
/*   Updated: 2022/06/23 21:15:50 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_command *command, t_shell *shell, int i)
{
	if (command->only_args[1] && !is_a_number(command->only_args[1]))
	{
		handle_errors(command, 257, command->only_args[1]);
		if (i == 0 && !shell->commands[1])
		{
			ft_putstr_fd("exit\n", 2);
			return (2);
		}
	}
	if (command->only_args[1] && is_a_number(command->only_args[1])
		&& command->only_args[2])
	{
		ft_putstr_fd("exit\n", 2);
		return (handle_errors(command, 256, command->only_args[0]));
	}
	if (command->only_args[1] && is_a_number(command->only_args[1])
		&& !command->only_args[2])
		command->errnum = ft_atoi(command->only_args[1]);
	if (i != 0 || shell->commands[++i])
		return (-1);
	ft_putstr_fd("exit\n", 2);
	return (2);
}

int	is_a_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i != 0 && !ft_isdigit(str[i]))
			|| (i == 0 && !ft_isdigit(str[i])
				&& str[i] != '+' && str[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}
