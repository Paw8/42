/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:26:40 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/06 16:50:58 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = 0;
	while (*s)
	{
		if (*s == (char)c)
			find = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (find);
}
