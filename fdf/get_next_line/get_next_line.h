/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:28 by pcordeir          #+#    #+#             */
/*   Updated: 2021/12/22 19:47:05 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	startnewline(char **s, int fd);
char	*splitline(char **s, int size);
void	addnewline(char **s, int *byte, int fd);
char	*endoffile(char **s);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);

#endif
