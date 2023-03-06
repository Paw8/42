/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:33:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/07/08 21:50:00 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_command *command)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putendl_fd(buf, command->fd[1]);
	free(buf);
	return (0);
}

int	ft_env(t_shell *shell, t_command *command)
{
	t_list	*print;

	if (command->only_args[1])
		return (handle_errors(command, 261, command->only_args[1]));
	print = shell->env;
	while (print->next)
	{
		ft_putstr_fd(((t_map *)print->content)->key, command->fd[1]);
		ft_putchar_fd('=', command->fd[1]);
		ft_putendl_fd(((t_map *)print->content)->value, command->fd[1]);
		print = print->next;
	}
	ft_putstr_fd(((t_map *)print->content)->key, command->fd[1]);
	ft_putchar_fd('=', command->fd[1]);
	ft_putendl_fd(((t_map *)print->content)->value, command->fd[1]);
	return (0);
}
