/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:12:22 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/14 12:26:28 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static char	**fsize(const char *s, char c, int *count);
static char	*ft_put(char *dest, const char *src, int size);
static void	arrbuild(const char *s, char c, char **arr, int *count);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	arr = fsize(s, c, &count);
	if (!s || !arr)
		return (NULL);
	arrbuild(s, c, arr, &count);
	while (count--)
	{
		if (!arr[count])
		{
			free(arr);
			return (NULL);
		}
	}
	return (arr);
}

static char	**fsize(const char *s, char c, int *count)
{
	char	**arr;

	*count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			(*count)++;
		while (*s != c && *s)
			s++;
	}
	arr = (char **)malloc(sizeof(char *) * ((*count) + 1));
	if (!arr)
		return (NULL);
	arr[*count] = 0;
	*count = 0;
	return (arr);
}

static char	*ft_put(char *dest, const char *src, int size)
{
	char	*ret;

	ret = dest;
	while (size--)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

static void	arrbuild(const char *s, char c, char **arr, int *count)
{
	char	*res;
	int		i;

	while (*s)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		if (*s)
		{
			res = (char *)s;
			while (*s != c && *s)
			{
				s++;
				i++;
			}
			arr[(*count)] = ft_put((char *)malloc(i + 1), res, i);
			if (!arr[(*count)])
				arr[(*count)] = 0;
			(*count)++;
		}
	}
}
