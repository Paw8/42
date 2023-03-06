/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:32:24 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/11 11:19:19 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_the_struct(t_shell *shell)
{
	shell->red_err = 0;
	if (trim_the_end(shell->std_inp) == (int) ft_strlen(shell->std_inp))
		return (1);
	read_dollar(shell, &shell->std_inp);
	if (parse_pipes(shell) != 0)
		return (1);
	if (split_to_tokens(shell->commands) != 0)
		return (1);
	if (manage_fds(shell) != 0)
		return (1);
	return (0);
}

int	parse_pipes(t_shell *shell)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	shell->n_cmds = count_commands(shell->std_inp, shell);
	if (shell->n_cmds < 0)
		return (1);
	shell->commands = ft_calloc(shell->n_cmds + 1, sizeof(t_command *));
	while (i < shell->n_cmds)
	{
		while (shell->std_inp[j] && shell->std_inp[j] != '|')
		{
			skip_quotes(shell->std_inp, &j);
			j++;
		}
		shell->commands[i] = ft_calloc(1, sizeof(t_command));
		shell->commands[i]->whole_str = ft_substr(shell->std_inp, k, j - k);
		shell->commands[i]->fd[0] = 0;
		shell->commands[i++]->fd[1] = 1;
		k = ++j;
	}
	return (0);
}

int	split_to_tokens(t_command **commands)
{
	int	i;
	int	count;

	i = 0;
	while (commands[i])
	{
		count_n_elems(commands[i]->whole_str, &count);
		commands[i]->splited_str = ft_calloc(count + 1, sizeof(char *));
		if (!commands[i]->splited_str)
			return (1);
		fill_splited_str(commands[i]->whole_str, count, commands[i]);
		commands[i]->only_args = ft_calloc(count_args(commands[i]->splited_str)
				+ 1, sizeof(char *));
		if (!commands[i]->only_args)
			return (1);
		separate_args_from_redirs(commands[i], commands[i]->splited_str);
		i++;
	}
	return (0);
}

int	manage_fds(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (shell->commands[i])
	{
		j = 0;
		while (shell->commands[i]->splited_str[j])
		{
			if (!ft_strncmp(shell->commands[i]->splited_str[j], "<<", 2))
				if (less_less(shell, shell->commands[i],
						shell->commands[i]->splited_str[j], 2))
					return (1);
			j++;
		}
		i++;
	}
	redirect_the_rest(shell, shell->commands);
	if (shell->red_err == 1)
		return (1);
	return (0);
}
