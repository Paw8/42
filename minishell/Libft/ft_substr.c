/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:47:56 by mokatova          #+#    #+#             */
/*   Updated: 2021/12/02 17:33:26 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (start >= ft_strlen(s) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	while (i < len && s[(size_t) start + i] != '\0')
		i++;
	string = (char *)malloc(sizeof(*string) * (i + 1));
	if (!string)
		return (0);
	while (i > 0)
	{
		string[j] = s[start];
		j++;
		start++;
		i--;
	}
	string[j] = '\0';
	return (string);
}
