/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:19:46 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:27:33 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*head;
	char	*tail;
	size_t	len;

	if (!s1 || !set)
		return ((char *)s1);
	head = (char *)s1;
	tail = (char *)s1 + ft_strlen(s1);
	while (*head && find_set(*head, set))
		head++;
	while (*(tail - 1) && head < tail && find_set(*(tail - 1), set))
		tail--;
	len = tail - head + 1;
	ret = malloc(len);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, head, len);
	return (ret);
}

static int	find_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
