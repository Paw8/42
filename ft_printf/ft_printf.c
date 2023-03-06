/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:31:34 by pcordeir          #+#    #+#             */
/*   Updated: 2021/11/24 12:21:43 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	rn_putchar(char c);
int	rn_string(char *s);
int	rn_int(int number);
int	rn_usgn(unsigned int nbr);
int	rn_hexl(unsigned int nbr);
int	rn_hexu(unsigned int nbr);
int	rn_point(unsigned long nbr);

int	format(const char **fmt, va_list edit, int ret)
{
	if (*(*fmt + 1) == 'c')
		ret = rn_putchar((char)va_arg(edit, int));
	else if (*(*fmt + 1) == 's')
		ret = rn_string((char *)va_arg(edit, char *));
	else if (*(*fmt + 1) == 'i' || *(*fmt + 1) == 'd')
		ret = rn_int(va_arg(edit, int));
	else if (*(*fmt + 1) == 'u')
		ret = rn_usgn(va_arg(edit, unsigned int));
	else if (*(*fmt + 1) == 'x')
		ret = rn_hexl(va_arg(edit, unsigned int));
	else if (*(*fmt + 1) == 'X')
		ret = rn_hexu(va_arg(edit, unsigned int));
	else if (*(*fmt + 1) == 'p')
		ret = rn_point(va_arg(edit, unsigned long));
	else if (*(*fmt + 1) == '%')
		return (rn_putchar(*++(*fmt)));
	else
		return (rn_putchar(*(*fmt + 1)));
	(*fmt)++;
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arguments;
	int		ret;

	ret = 0;
	va_start(arguments, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			ret += rn_putchar(*fmt);
		else
			ret += format(&fmt, arguments, ret);
		fmt++;
	}
	va_end (arguments);
	if (ret >= 0)
		return (ret);
	else
		return (-1);
}
