/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:08:17 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/05 17:56:25 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_default(void)
{
	signal(SIGINT, &parent_ctrl_c_prompt);
	signal(SIGQUIT, SIG_IGN);
}

void	parent_ctrl_c_prompt(int sign)
{
	if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	parent_ctrl_c_no_prompt(int sign)
{
	if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
	}
}

void	parent_process(void)
{
	signal(SIGINT, &parent_ctrl_c_no_prompt);
	signal(SIGQUIT, &slash_quit);
}

void	slash_quit(int sign)
{
	if (sign == SIGQUIT)
		ft_putstr_fd("Quit\n", 1);
}
