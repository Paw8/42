/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:28:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/07/09 17:21:20 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_sarray(char **array)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (array[i + 1])
	{
		j = 0;
		while (*(array[i] + j) == *(array[i + 1] + j))
			j++;
		if ((*(array[i] + j) > *(array[i + 1] + j) \
			&& *(array[i] + j) != '=') || *(array[i + 1] + j) == '=')
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	ft_export(t_shell *shell, t_command *command, int i)
{
	t_list	*envar;
	int		j;

	j = 1;
	if (!command->only_args[1])
		return (export_only(shell, command));
	while (command->only_args[j])
	{
		if (check_argument(command->only_args[j]))
			handle_errors(command, 260, command->only_args[j]);
		else
		{
			if (i != 0 || shell->commands[i + 1])
				return (0);
			envar = find_var(shell->env, command->only_args[j]);
			change_value(shell, command->only_args[j], envar);
		}
		j++;
	}
	return (0);
}

int	export_only(t_shell *shell, t_command *command)
{
	char	**env_array;
	int		i;

	i = 0;
	env_array = get_env_array(shell->env);
	sort_sarray(env_array);
	while (env_array[i])
	{
		ft_putstr_fd("declare -x ", command->fd[1]);
		ft_putendl_fd(env_array[i], command->fd[1]);
		i++;
	}
	free_array(env_array);
	return (0);
}

void	change_value(t_shell *shell, char *str, t_list *envar)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (envar)
	{
		free(((t_map *)envar->content)->value);
		((t_map *)envar->content)->value = ft_substr(str, ++i, ft_strlen(str));
	}
	else
		ft_lstadd_back(&shell->env, ft_lstnew(split_env(str)));
}
