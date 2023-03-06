/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:54:09 by mokatova          #+#    #+#             */
/*   Updated: 2022/05/19 17:49:02 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*save_env(char **envp)
{
	int		i;
	t_list	*env;

	if (!envp[0])
		return (NULL);
	env = ft_lstnew(split_env(envp[0]));
	i = 1;
	while (envp[i])
	{
		ft_lstadd_back(&env, ft_lstnew(split_env(envp[i])));
		i++;
	}
	return (env);
}

t_map	*split_env(char *env_var)
{
	int		i;
	char	*sep;
	t_map	*splited;

	splited = malloc(sizeof(t_map));
	sep = ft_strchr(env_var, '=');
	if (sep)
	{
		i = ft_strlen(env_var) - ft_strlen(sep);
		splited->key = ft_calloc(i + 1, sizeof(char));
		ft_strlcpy(splited->key, env_var, i + 1);
		splited->value = ft_strdup(env_var + i + 1);
	}
	else
	{
		splited->key = ft_strdup(env_var);
		splited->value = ft_strdup("");
	}
	return (splited);
}
