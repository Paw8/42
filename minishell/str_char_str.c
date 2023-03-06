/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:32:44 by mokatova          #+#    #+#             */
/*   Updated: 2022/06/16 18:33:36 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_char_str(char const *s1, char c, char const *s2)
{
	char	*string;
	int		len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 2);
	string = (char *)malloc(sizeof(char) * len);
	if (!string)
		return (0);
	while (i < ft_strlen(s1))
	{
		string[i] = s1[i];
		i++;
	}
	string[i++] = c;
	while (j < ft_strlen(s2))
	{
		string[i++] = s2[j++];
	}
	string[i] = '\0';
	return (string);
}
