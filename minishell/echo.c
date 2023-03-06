/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:30:01 by mokatova          #+#    #+#             */
/*   Updated: 2022/06/23 17:57:10 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_command *command)
{
	int	n_flag;
	int	i;
	int	tmp;

	n_flag = 0;
	i = 1;
	if (command->only_args[1]
		&& ft_strncmp(command->only_args[1], "-n\0", 3) == 0)
	{
		n_flag = 1;
		i = 2;
	}
	while (command->only_args[i])
	{
		tmp = i;
		if (i != tmp)
			ft_putstr_fd(" ", command->fd[1]);
		ft_putstr_fd(command->only_args[i++], command->fd[1]);
	}
	if (!n_flag)
		ft_putstr_fd("\n", command->fd[1]);
	return (0);
}
