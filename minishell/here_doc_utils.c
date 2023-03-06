/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:35:50 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/06 17:44:08 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prepare_heredoc(t_shell *shell, t_command *command, char *str, int *i)
{
	if (command->fd[0] != 0)
		close(command->fd[0]);
	skip_spaces(str, i);
	if (str[*i] == '\0')
	{
		handle_errors(command, 258, "\0");
		shell->red_err = 1;
		return (1);
	}
	command->fd[0] = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (0);
}

void	putstr_nl(char *str, t_command *command)
{
	ft_putstr_fd(str, command->fd[0]);
	ft_putstr_fd("\n", command->fd[0]);
}

int	clean_n_print(char *line, char *str, int i)
{
	char	*str2;

	str2 = "minishell: warning: here-document delimited by end-of-file";
	free(line);
	unlink(".heredoc_tmp");
	printf("%s (wanted `%s')\n", str2, &str[i]);
	return (1);
}

int	print_n_return_err(t_command *command, t_shell *shell)
{
	handle_errors(command, errno, NULL);
	shell->red_err = 1;
	return (1);
}
