/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:59:28 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/07 22:01:44 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(len + 1);
	if (ret)
	{
		i = 0;
		while (start < ft_strlen(s) + 1 && s[start] && len--)
			ret[i++] = s[start++];
		ret[i] = '\0';
		return (ret);
	}
	else
		return (NULL);
}
