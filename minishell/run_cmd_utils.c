/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:44:33 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/11 09:47:00 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_correct_path(char *cmd, char **paths)
{
	char	*possible_path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	while (paths && paths[i])
	{
		possible_path = str_char_str(paths[i], '/', cmd);
		if (access(possible_path, X_OK) == 0)
			return (possible_path);
		free(possible_path);
		i++;
	}
	return (NULL);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	child_process(t_shell *shell, t_command *command, char *w_path, int i)
{
	char	**envp;
	int		j;

	j = 0;
	connect_pipe(command);
	while (shell->commands[j])
	{
		if (j != i)
			close_pipe(shell->commands[j]);
		j++;
	}
	envp = get_env_array(shell->env);
	if (execve(w_path, command->only_args, envp) == -1)
		handle_errors(command, errno, NULL);
	close_pipe(command);
	free_array(envp);
	clean_cmds(shell);
	free(shell->std_inp);
	exit(0);
}

char	**get_env_array(t_list *env)
{
	char	**array;
	t_list	*temp;
	int		i;

	temp = env;
	i = 0;
	array = ft_calloc((ft_lstsize(env) + 1), sizeof(char *));
	while (i < ft_lstsize(env))
	{
		array[i] = ft_calloc(ft_strlen(((t_map *)temp->content)->key)
				+ ft_strlen(((t_map *)temp->content)->value) + 5, 1);
		ft_strlcpy(array[i], ((t_map *)temp->content)->key,
			ft_strlen(((t_map *)temp->content)->key) + 1);
		array[i][ft_strlen(array[i])] = '=';
		ft_strlcpy(array[i] + ft_strlen(array[i]), ((t_map *)temp->content)
			->value, ft_strlen(((t_map *)temp->content)->value) + 1);
		temp = temp->next;
		i++;
	}
	return (array);
}

void	check_kids(t_shell *shell)
{
	int			status;
	int			i;

	i = 0;
	if (shell->commands == NULL)
		return ;
	status = 0;
	while (shell->commands[i])
	{
		if (shell->commands[i]->pid != 0
			&& waitpid(shell->commands[i]->pid, &status, 0) != -1)
		{
			if (WIFEXITED(status))
				shell->commands[i]->errnum = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell->commands[i]->errnum = 128 + WTERMSIG(status);
		}
		i++;
	}
	shell->errnum = shell->commands[--i]->errnum;
	parent_default();
}
