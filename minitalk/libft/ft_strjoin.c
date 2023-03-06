/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:49:43 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:26:22 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size;
	char	*ret;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(size);
	if (ret)
	{
		i = 0;
		while (size--)
		{
			while (*s1 && size--)
				ret[i++] = *s1++;
			ret[i++] = *s2++;
		}
		return (ret);
	}
	else
		return (NULL);
}
