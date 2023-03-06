/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:11:55 by mokatova          #+#    #+#             */
/*   Updated: 2021/12/02 17:48:42 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*string;
	char	chr;

	string = (char *) str;
	chr = (char) c;
	len = ft_strlen(str);
	while (len > 0)
	{
		if (string[len] == chr)
			return (&string[len]);
		len--;
	}
	if (string[len] == chr)
		return (string);
	return (0);
}
