/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:59:28 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:27:38 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
