/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:44:20 by mokatova          #+#    #+#             */
/*   Updated: 2022/06/23 19:56:09 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_dollar(t_shell *shell, char **line)
{
	int		i[3];
	char	*replace_with;

	i[0] = 0;
	i[1] = 0;
	while ((*line)[i[0]])
	{
		if ((*line)[i[0]] == '\'' && i[1] == 0)
			i[1] = 1;
		else if ((*line)[i[0]] == '\'' && i[1] == 1)
			i[1] = 0;
		if ((*line)[i[0]] == '$' && i[1] == 0)
		{
			i[2] = fill_repl(&(*line)[i[0] + 1], shell, &replace_with);
			if (replace_with)
			{
				(*line) = insert((*line), replace_with, i[0], i[2] + 1);
				i[0] += ft_strlen(replace_with);
			}
			if (replace_with)
				free(replace_with);
		}
		i[0]++;
	}
}

int	fill_repl(char *line, t_shell *shell, char **replace)
{
	t_list	*envar;
	int		i;

	if (line[0] == '?')
		*replace = ft_itoa(shell->errnum);
	if (line[0] == '0')
		*replace = ft_strdup("minishell");
	if (line[0] == '\0')
		*replace = ft_strdup("$");
	if (line[0] == '0' || line[0] == '?' || line[0] == '\0')
		return (1);
	envar = find_var(shell->env, line);
	if (!envar)
	{
		*replace = ft_strdup("");
		i = 0;
		while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
			i++;
		return (i);
	}
	*replace = ft_strdup(((t_map *)envar->content)->value);
	return ((int)ft_strlen(((t_map *)envar->content)->key));
}

t_list	*find_var(t_list *env, char *line)
{
	int		i;
	char	*key_name;
	t_list	*var;

	i = 0;
	if (!(ft_isalpha(line[0]) || line[0] == '_'))
		return (NULL);
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	key_name = ft_substr(line, 0, i);
	var = is_env_var(env, key_name);
	free(key_name);
	return (var);
}

t_list	*is_env_var(t_list *env, char *key)
{
	t_list	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strncmp(key, ((t_map *)temp->content)->key, ft_strlen(key) + 1))
			break ;
		temp = temp->next;
	}
	return (temp);
}

char	*insert(char *line, char *rep, int dollar_i, int remove)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(ft_strlen(line) + ft_strlen(rep) + 1, sizeof(char));
	while (i < dollar_i && line[i])
	{
		new[i] = line[i];
		i++;
	}
	i = 0;
	while (rep && rep[i])
	{
		new[i + dollar_i] = rep[i];
		i++;
	}
	i = dollar_i + remove;
	while (line[i])
	{
		new[ft_strlen(new)] = line[i];
		i++;
	}
	free(line);
	return (new);
}
