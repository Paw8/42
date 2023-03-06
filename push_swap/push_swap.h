/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:21:56 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/15 11:26:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct _stack_ {
	int				value;
	int				svalue;
	char			*bivalue;
	struct _stack_	*next;
}t_stack;

void		checkall(int argc, char **argv, int **arr);
void		checkinput(int argc, char **argv, int **arr);
int			checkprefix(char **argv, int *i);
int			checksize(char **argv, int i, int **arr);
void		checkduplicate(int *arr, int size);
void		error(int *arr);
t_stack		*newnode(int nbr);
void		addnode(int nbr, t_stack *root);
int			issorted(t_stack *src);
void		setsvalue(t_stack *src, int size);
void		swap(t_stack **dest, char c);
void		sswap(t_stack **a, t_stack **b);
void		push(t_stack **src, t_stack **dest, char c);
void		rotate(t_stack **src, char c);
void		rrotate(t_stack **src, char c);
void		rotateboth(t_stack **a, t_stack **b);
void		rrotateboth(t_stack **a, t_stack **b);
void		push_swap(t_stack **a, int size);
void		freestack(t_stack *root);
long		ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			findsmallest(t_stack *src);
void		sort3(t_stack **a);
void		sort4(t_stack **a, t_stack **b);
void		sortsmall(t_stack **src, t_stack **b, int size);
void		setbivalue(t_stack *a);
char		*ft_strjoin(char *dest, char *src);
char		*ft_itobi(int nbr);
void		action(t_stack **a);
void		sortbig(t_stack **a, t_stack **b, int size);

#endif
