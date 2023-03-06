/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:56:27 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/10 23:52:27 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.env = save_env(envp);
	shell.commands = NULL;
	parent_default();
	while (1)
	{
		shell.std_inp = readline("minishell: ");
		if (!shell.std_inp)
			break ;
		if (ft_strlen(shell.std_inp) > 0)
			add_history(shell.std_inp);
		if (fill_the_struct(&shell) == 0)
		{
			if (run_the_damn_thing(&shell) == 2)
				break ;
		}
		check_kids(&shell);
		free(shell.std_inp);
		clean_cmds(&shell);
	}
	clear_everything(&shell);
	return (shell.errnum);
}
