/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_n_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:48:53 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/08 21:39:33 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command(t_command *cmd)
{
	if (cmd->whole_str)
		free(cmd->whole_str);
	if (cmd->splited_str && cmd->splited_str[0])
		free_array(cmd->splited_str);
	else if (cmd->splited_str)
		free(cmd->splited_str);
	if (cmd->only_args && cmd->only_args[0])
		free_array(cmd->only_args);
	else if (cmd->only_args)
		free(cmd->only_args);
}

void	clean_cmds(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->commands != NULL && shell->commands[i])
	{
		free_command(shell->commands[i]);
		free(shell->commands[i]);
		i++;
	}
	free(shell->commands);
	shell->commands = NULL;
}

void	clear_everything(t_shell *shell)
{
	int	i;

	i = 0;
	clear_list(&shell->env);
	while (shell->commands != NULL && shell->commands[i])
		i++;
	if (shell->commands != NULL && shell->commands[--i])
		shell->errnum = shell->commands[i]->errnum;
	clean_cmds(shell);
	rl_clear_history();
	if (shell->std_inp)
		free((void *) shell->std_inp);
	else
		ft_putstr_fd("exit\n", 1);
}

void	clear_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free((void *)((t_map *)tmp->content)->key);
		free((void *)((t_map *)tmp->content)->value);
		free((void *) tmp->content);
		free((void *) tmp);
	}
	*list = NULL;
}
