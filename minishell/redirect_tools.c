/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:58:09 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/09 19:49:54 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	less_less(t_shell *shell, t_command *command, char *str, int i)
{
	char	*line;

	if (prepare_heredoc(shell, command, str, &i) == 1)
		return (1);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!*line)
			return (clean_n_print(line, str, i));
		if (ft_strncmp(&str[i], line, ft_strlen(&str[i]) + 1) == 0)
			break ;
		read_dollar(shell, &line);
		putstr_nl(line, command);
		free(line);
	}
	free(line);
	close(command->fd[0]);
	command->fd[0] = open(".heredoc_tmp", O_RDONLY);
	unlink(".heredoc_tmp");
	if (command->fd[0] < 0)
		return (print_n_return_err(command, shell));
	return (0);
}

void	redirect_the_rest(t_shell *s, t_command **commands)
{
	int	i[2];

	i[0] = -1;
	while (commands[++i[0]])
	{
		i[1] = -1;
		while (commands[i[0]]->splited_str[++i[1]])
		{
			if (!ft_strncmp(commands[i[0]]->splited_str[i[1]], "<", 1))
			{
				if (less(s, commands[i[0]], commands[i[0]]->splited_str[i[1]]))
					break ;
			}
			else if (!ft_strncmp(commands[i[0]]->splited_str[i[1]], ">>", 2))
			{
				if (mr_mr(s, commands[i[0]], commands[i[0]]->splited_str[i[1]]))
					break ;
			}
			else if (!ft_strncmp(commands[i[0]]->splited_str[i[1]], ">", 1))
			{
				if (more(s, commands[i[0]], commands[i[0]]->splited_str[i[1]]))
					break ;
			}
		}
	}
}

int	mr_mr(t_shell *shell, t_command *command, char *str)
{
	int	i;

	i = 2;
	if (command->fd[1] != 1)
		close(command->fd[1]);
	skip_spaces(str, &i);
	if (str[i] == '\0')
	{
		handle_errors(command, 258, "\0");
		shell->red_err = 1;
		return (1);
	}
	command->fd[1] = open(&str[i], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (command->fd[1] < 0)
	{
		handle_errors(command, errno, &str[i]);
		shell->red_err = 1;
		return (1);
	}
	return (0);
}

int	more(t_shell *shell, t_command *command, char *str)
{
	int	i;

	i = 1;
	if (command->fd[1] != 1)
		close(command->fd[1]);
	skip_spaces(str, &i);
	if (str[i] == '\0')
	{
		handle_errors(command, 258, "\0");
		shell->red_err = 1;
		return (1);
	}
	command->fd[1] = open(&str[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (command->fd[1] < 0)
	{
		handle_errors(command, errno, &str[i]);
		shell->red_err = 1;
		return (1);
	}
	return (0);
}

int	less(t_shell *shell, t_command *command, char *str)
{
	int	i;

	i = 1;
	if (str[i] == '<')
		return (0);
	if (command->fd[0] != 0)
		close(command->fd[0]);
	skip_spaces(str, &i);
	if (str[i] == '\0')
	{
		handle_errors(command, 258, "\0");
		shell->red_err = 1;
		return (1);
	}
	command->fd[0] = open(&str[i], O_RDONLY);
	if (command->fd[0] < 0 || access(&str[i], R_OK) == -1)
	{
		handle_errors(command, errno, &str[i]);
		shell->red_err = 1;
		return (1);
	}
	return (0);
}
