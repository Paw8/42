/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:23:07 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/07 19:38:14 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_shell *shell, t_command *command, int i)
{
	char		*newpwd;
	struct stat	path_check;

	newpwd = NULL;
	if (command->only_args[2])
		return (handle_errors(command, 256, command->only_args[0]));
	if (command->only_args[1]
		&& lstat(command->only_args[1], &path_check) == -1)
		return (handle_errors(command, 261, command->only_args[1]));
	if (i != 0 || shell->commands[i + 1])
		return (0);
	command->errnum = 0;
	if (command->only_args[1] == NULL)
		chdir(((t_map *)find_var(shell->env, "HOME")->content)->value);
	else
		chdir(command->only_args[1]);
	change_old(shell);
	newpwd = getcwd(newpwd, 1000);
	change_new(shell, newpwd);
	if (newpwd)
		free(newpwd);
	return (0);
}

void	change_old(t_shell *shell)
{
	t_list	*old;
	t_list	*new;
	char	*tmp;

	old = find_var(shell->env, "OLDPWD");
	new = find_var(shell->env, "PWD");
	if (old)
	{
		free(((t_map *)old->content)->value);
		((t_map *)old->content)->value
			= ft_strdup(((t_map *)new->content)->value);
	}
	else
	{
		tmp = ft_strjoin("OLDPWD=", ((t_map *)new->content)->value);
		ft_lstadd_back(&shell->env, ft_lstnew(split_env(tmp)));
		free(tmp);
	}
}

void	change_new(t_shell *shell, char *newpwd)
{
	t_list	*new;

	new = find_var(shell->env, "PWD");
	free(((t_map *)new->content)->value);
	((t_map *)new->content)->value = ft_strdup(newpwd);
}
