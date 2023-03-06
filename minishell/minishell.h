/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:16:35 by mokatova          #+#    #+#             */
/*   Updated: 2022/07/11 00:19:32 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_command
{
	char	*whole_str;
	char	**splited_str;
	char	**only_args;
	int		fd[2];
	pid_t	pid;
	int		errnum;
}	t_command;

typedef struct s_shell
{
	t_list		*env;
	char		*std_inp;
	int			n_cmds;
	t_command	**commands;
	int			errnum;
	int			red_err;
}	t_shell;

typedef struct s_map
{
	char	*key;
	char	*value;
}	t_map;

/////save_env.c
t_list	*save_env(char **envp);
t_map	*split_env(char *env_var);
/////read_dollar.c
void	read_dollar(t_shell *shell, char **line);
int		fill_repl(char *line, t_shell *shell, char **replace);
t_list	*find_var(t_list *env, char *line);
t_list	*is_env_var(t_list *env, char *key);
char	*insert(char *line, char *rep, int dollar_i, int remove);
/////fill_the_structs.c
int		fill_the_struct(t_shell *shell);
int		parse_pipes(t_shell *shell);
int		split_to_tokens(t_command **commands);
int		manage_fds(t_shell *shell);
/////parse_utils.c
int		count_commands(char *input, t_shell *shell);
void	count_n_elems(char *str, int *count);
void	fill_splited_str(char *str, int count, t_command *command);
void	separate_args_from_redirs(t_command *command, char **splited);
char	*remove_q_marks(char *str, int flag);
/////skipping_symbols.c
void	skip_quotes(char *input, int *i);
void	skip_spaces(char *str, int *i);
int		is_space(char c);
void	skip_to_arg(char *str, int *i);
void	skip_the_rest(char *str, int *i);
/////parse_utils2.c
int		count_args(char **splited);
int		count_len_wtht_quotes(char *str);
int		trim_the_end(char *str);
/////redirect_tools.c
int		less_less(t_shell *shell, t_command *command, char *str, int i);
void	redirect_the_rest(t_shell *s, t_command **commands);
int		mr_mr(t_shell *shell, t_command *command, char *str);
int		more(t_shell *shell, t_command *command, char *str);
int		less(t_shell *shell, t_command *command, char *str);
/////running_the_commands.c
int		run_the_damn_thing(t_shell *shell);
int		create_pipe(t_command *command, t_command *command2);
int		check_for_builtins(t_shell *shell, t_command *command, int i);
int		just_go_to_execve(t_shell *shell, t_command *command, int i);
void	close_pipe(t_command *command);
/////str_char_str.c
char	*str_char_str(char const *s1, char c, char const *s2);
/////run_cmd_utils.c
char	*get_correct_path(char *cmd, char **paths);
void	free_array(char **argv);
void	child_process(t_shell *shell, t_command *command, char *w_path, int i);
char	**get_env_array(t_list *env);
void	check_kids(t_shell *shell);
/////clean_n_free.c
void	free_command(t_command *cmd);
void	clean_cmds(t_shell *shell);
void	clear_everything(t_shell *shell);
void	clear_list(t_list **list);
/////error_management.c
int		handle_errors(t_command *command, int errnum, char *str);
void	syntax_error(t_command *command, char *str);
void	some_other_error(t_command *command, int errnum, char *str);
void	cmd_not_found(t_command *command);
void	numeric_needed(t_command *command, char *str);
/////here_doc_utils.c
int		prepare_heredoc(t_shell *shell, t_command *command, char *str, int *i);
void	putstr_nl(char *str, t_command *command);
int		clean_n_print(char *line, char *str, int i);
int		print_n_return_err(t_command *command, t_shell *shell);
/////echo.c
int		ft_echo(t_command *command);
/////exit.c
int		ft_exit(t_command *command, t_shell *shell, int i);
int		is_a_number(char *str);
/////error_utils.c
void	too_many_args(t_command *command, char *str);
void	not_valid_identifier(t_command *command, char *str);
void	cd_no_such(t_command *command, char *str);
/////signal_handling.c
void	parent_default(void);
void	parent_ctrl_c_prompt(int sign);
void	parent_ctrl_no_prompt(int sign);
void	parent_process(void);
void	slash_quit(int sign);
////builtin.c
int		ft_pwd(t_command *command);
int		ft_env(t_shell *shell, t_command *command);
/////unset.c
int		ft_unset(t_command *command, t_shell *shell, int i);
int		check_argument(char *str);
void	del_envar(t_shell *shell, t_list *envar);
/////export.c
int		ft_export(t_shell *shell, t_command *command, int i);
void	sort_sarray(char **array);
int		export_only(t_shell *shell, t_command *command);
void	change_value(t_shell *shell, char *str, t_list *envar);
/////cd.c
int		ft_cd(t_shell *shell, t_command *command, int i);
void	change_old(t_shell *shell);
void	change_new(t_shell *shell, char *newpwd);
/////run_cmd_utils2.c
void	connect_pipe(t_command *command);

#endif