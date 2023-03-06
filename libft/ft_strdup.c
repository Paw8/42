/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:05:35 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:26:12 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
