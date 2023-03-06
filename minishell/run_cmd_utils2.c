/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:17:41 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/11 00:18:39 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	connect_pipe(t_command *command)
{
	if (command->fd[0] != 0)
	{
		dup2(command->fd[0], 0);
		close(command->fd[0]);
	}
	if (command->fd[1] != 1)
	{
		dup2(command->fd[1], 1);
		close(command->fd[1]);
	}
}
