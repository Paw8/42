/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:23:06 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/09 19:53:48 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_commands(char *input, t_shell *shell)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (input && input[i])
	{
		skip_quotes(input, &i);
		if (input[i] == '|')
		{
			if (input[i + 1] && input[i + 1] != '|')
				count++;
			else
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `",
					2);
				ft_putstr_fd("|'\n", 2);
				shell->errnum = 2;
				return (-1);
			}
		}
		i++;
	}
	return (count);
}

void	count_n_elems(char *str, int *count)
{
	int	i;

	i = 0;
	(*count) = 1;
	while (str[i])
	{
		skip_spaces(str, &i);
		while (str[i] && !is_space(str[i]))
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				skip_quotes(str, &i);
				i++;
			}
			else if (str[i] == '<' || str[i] == '>')
				skip_to_arg(str, &i);
			else
				skip_the_rest(str, &i);
			if (str[i] == '<' || str[i] == '>')
				break ;
		}
		if (!str[i] || (is_space(str[i]) && !str[i + trim_the_end(&str[i])]))
			break ;
		(*count)++;
	}
}

void	fill_splited_str(char *str, int count, t_command *command)
{
	int	is[3];

	is[0] = 0;
	is[1] = 0;
	while (is[0] < count)
	{
		skip_spaces(str, &is[1]);
		is[2] = is[1];
		while (str[is[2]] && !is_space(str[is[2]]))
		{
			if (str[is[2]] == '\'' || str[is[2]] == '\"')
			{
				skip_quotes(str, &is[2]);
				is[2]++;
			}
			else if (str[is[2]] == '<' || str[is[2]] == '>')
				skip_to_arg(str, &is[2]);
			else
				skip_the_rest(str, &is[2]);
			if (str[is[2]] == '<' || str[is[2]] == '>')
				break ;
		}
		command->splited_str[is[0]++] = ft_substr(str, is[1], is[2] - is[1]);
		is[1] = is[2];
	}
}

void	separate_args_from_redirs(t_command *command, char **splited)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splited[i])
	{
		if (splited[i][0] != '<' && splited[i][0] != '>')
		{
			splited[i] = remove_q_marks(splited[i], 1);
			command->only_args[j++] = remove_q_marks(splited[i++], 0);
		}
		else
		{
			splited[i] = remove_q_marks(splited[i], 1);
			i++;
		}
	}
}

char	*remove_q_marks(char *str, int flag)
{
	int		i;
	int		j;
	char	c;
	char	*no_quotes;

	i = 0;
	j = 0;
	no_quotes = ft_calloc(count_len_wtht_quotes(str) + 1, sizeof(char));
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				no_quotes[j++] = str[i++];
		}
		else
			no_quotes[j++] = str[i];
		i++;
	}
	if (flag == 1)
		free(str);
	return (no_quotes);
}
