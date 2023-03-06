/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipping_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:54:40 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/07 22:34:37 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_quotes(char *input, int *i)
{
	if (input[*i] == '\'')
	{
		(*i)++;
		while (input[*i] && input[*i] != '\'')
			(*i)++;
	}
	else if (input[*i] == '\"')
	{
		(*i)++;
		while (input[*i] && input[*i] != '\"')
			(*i)++;
	}
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && is_space(str[*i]))
		(*i)++;
}

int	is_space(char c)
{
	if ((c <= 13 && c >= 9) || c == 32)
		return (1);
	return (0);
}

void	skip_to_arg(char *str, int *i)
{
	while (str[*i] && (str[*i] == '<' || str[*i] == '>'))
		(*i)++;
	while (str[*i] && is_space(str[*i]))
		(*i)++;
}

void	skip_the_rest(char *str, int *i)
{
	while (str[*i] && !is_space(str[*i]) && str[*i] != '<'
		&& str[*i] != '>' && str[*i] != '\'' && str[*i] != '\"')
		(*i)++;
}
