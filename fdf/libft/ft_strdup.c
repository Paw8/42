/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:05:35 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/07 18:25:32 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ret;

	i = ft_strlen(s) + 1;
	ret = (char *)malloc(i);
	if (ret)
	{
		while (i--)
			ret[i] = s[i];
		return (ret);
	}
	else
		return (NULL);
}
