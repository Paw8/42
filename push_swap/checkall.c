/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:51:00 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/01 14:22:02 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkall(int argc, char **argv, int **arr)
{
	int	i;

	checkinput(argc, argv, arr);
	i = 1;
	while (i < argc)
	{
		*(*arr + i - 1) = checksize(argv, i, arr);
		i++;
	}
	checkduplicate(*arr, argc - 1);
}

void	checkinput(int argc, char **argv, int **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = checkprefix(argv, &i);
		if (j == -1)
			error(*arr);
		while (*(argv[i] + j) != '\0')
		{
			if (*(argv[i] + j) < 48 || *(argv[i] + j) > 57)
				error(*arr);
			else
				j++;
		}
		i++;
	}
}

int	checkprefix(char **argv, int *i)
{
	int	count;

	count = 0;
	if (*argv[*i] == 43 || *argv[*i] == 45)
	{
		count = 1;
		if (*(argv[*i] + count) == '\0')
			return (-1);
	}
	while (*(argv[*i] + count) == '0' && *(argv[*i] + count) != '\0')
		count++;
	if (ft_strlen(argv[*i] + count) > 10)
		return (-1);
	return (count);
}

int	checksize(char **argv, int i, int **arr)
{
	long	size;

	size = ft_atoi(argv[i]);
	if (size != (int)size)
		error(*arr);
	return ((int)size);
}

void	checkduplicate(int *arr, int size)
{
	int	i;

	while (size--)
	{
		i = 0;
		while (i < size)
			if (*(arr + size) == *(arr + i++))
				error(arr);
	}
}
