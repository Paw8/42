/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:59:51 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/07 14:27:27 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ret;
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && n)
	{
		ret = (char *)s1;
		i = 0;
		while (*s1 == s2[i] && s2[i] && n && *s1)
		{
			s1++;
			i++;
			n--;
		}
		if (!s2[i])
			return (ret);
		else if (!i)
		{
			n--;
			s1++;
		}
	}
	return (NULL);
}
