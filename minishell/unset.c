/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:47:22 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/07 22:21:20 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_command *command, t_shell *shell, int i)
{
	int		j;
	t_list	*envar;

	j = 1;
	while (command->only_args[j])
	{
		if (check_argument(command->only_args[j]))
			handle_errors(command, 260, command->only_args[j]);
		else
		{
			if (i != 0 || shell->commands[i + 1])
				return (0);
			envar = find_var(shell->env, command->only_args[j]);
			if (envar)
				del_envar(shell, envar);
		}
		j++;
	}
	return (0);
}

int	check_argument(char *str)
{
	int	i;

	i = 0;
	if ((str[0] >= '0' && str[0] <= '9') || str[0] == '=')
		return (1);
	while (str[i])
	{
		if ((str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < 'a' || str[i] > 'z')
			&& (str[i] < '0' || str[i] > '9')
			&& str[i] != '_' && str[i] != '=')
			return (1);
		i++;
	}
	return (0);
}

void	del_envar(t_shell *shell, t_list *envar)
{
	t_map	*var;
	t_list	*tmp;

	tmp = shell->env;
	if (tmp == envar)
		shell->env = tmp->next;
	else
	{
		while (tmp->next != envar)
			tmp = tmp->next;
		tmp->next = envar->next;
	}
	if (envar)
	{
		var = envar->content;
		if (var)
		{
			if (var->key)
				free(var->key);
			if (var->value)
				free(var->value);
			free(var);
		}
		free(envar);
	}
}
