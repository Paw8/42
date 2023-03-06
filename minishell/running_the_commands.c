/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_the_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:13:04 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/11 09:45:23 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_the_damn_thing(t_shell *shell)
{
	int	i;
	int	ret_val;

	i = 0;
	parent_process();
	while (shell->commands[i])
	{
		if (shell->commands[i + 1])
			create_pipe(shell->commands[i], shell->commands[i + 1]);
		ret_val = check_for_builtins(shell, shell->commands[i], i);
		if (ret_val == 2)
			return (2);
		if (ret_val == 1)
			just_go_to_execve(shell, shell->commands[i], i);
		close_pipe(shell->commands[i]);
		i++;
	}
	return (0);
}

int	create_pipe(t_command *command, t_command *command2)
{
	int	fd[2];

	if (pipe(fd) < 0)
		return (handle_errors(command, errno, NULL));
	if (command->fd[1] == 1)
		command->fd[1] = fd[1];
	else
		close(fd[1]);
	if (command2->fd[0] == 0)
		command2->fd[0] = fd[0];
	else
		close(fd[0]);
	return (0);
}

int	check_for_builtins(t_shell *shell, t_command *command, int i)
{
	if (ft_strncmp(command->splited_str[0], "echo\0", 5) == 0)
		return (ft_echo(command));
	else if (ft_strncmp(command->splited_str[0], "exit\0", 5) == 0)
		return (ft_exit(command, shell, i));
	else if (ft_strncmp(command->splited_str[0], "pwd\0", 4) == 0)
		return (ft_pwd(command));
	else if (ft_strncmp(command->splited_str[0], "env\0", 4) == 0)
		return (ft_env(shell, command));
	else if (ft_strncmp(command->splited_str[0], "export\0", 7) == 0)
		return (ft_export(shell, command, i));
	else if (ft_strncmp(command->splited_str[0], "unset\0", 6) == 0)
		return (ft_unset(command, shell, i));
	else if (ft_strncmp(command->splited_str[0], "cd\0", 3) == 0)
		return (ft_cd(shell, command, i));
	else if (!command->only_args[0])
		return (3);
	return (1);
}

int	just_go_to_execve(t_shell *shell, t_command *command, int i)
{
	char	**paths;
	t_list	*path_var;
	char	*cmd_w_path;

	path_var = find_var(shell->env, "PATH");
	if (!path_var)
	{
		ft_putstr_fd("minishell: return PATH variable into env >:(\n", 2);
		return (-1);
	}
	paths = ft_split(((t_map *)path_var->content)->value, ':');
	cmd_w_path = get_correct_path(command->splited_str[0], paths);
	free_array(paths);
	if (!cmd_w_path)
		return (handle_errors(command, 259, NULL));
	command->pid = fork();
	if (command->pid < 0)
		return (handle_errors(command, errno, NULL));
	if (command->pid == 0)
		child_process(shell, command, cmd_w_path, i);
	free(cmd_w_path);
	return (0);
}

void	close_pipe(t_command *command)
{
	if (command->fd[0] != 0)
		close(command->fd[0]);
	if (command->fd[1] != 1)
		close(command->fd[1]);
}
