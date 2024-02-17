/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:05:18 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/16 17:04:57 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../l_libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "err_msg.h"
# include <sys/ioctl.h>

extern int	g_exit;

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREATER,
	T_DLESS,
	T_DGREATER,
	T_PIPE,
	T_NL
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*previous;
}					t_token;

typedef struct s_minishell
{
	char			*user_input;
	t_token			*tokens;
	t_token			*current_token;
	char			**cmd_args;
	char			**envp;
	char			**paths;
	int				exit_status;
	int				fd_stdin;
	int				fd_stdout;
	int				heredoc;
	int				piped;
	int				in_redirect;
	int				out_redirect;
	char			*err_msg;
	int				logo;
	struct termios	original_term;
}					t_minishell;

/*--------------------INIT_SHELL-------------------*/
char	**ft_extract_envp(char **envp);
void	ft_init_prompt(t_minishell *shell);
void	ft_init_shell(t_minishell *shell, int argc, char **argv, char **envp);
void	ft_init_logo(void);
void	ft_init_logo_1(void);

/*----------------------SIGNALS--------------------*/
void	ft_signals(void);
void	ft_child_signals(void);
void	sigint_handler_heredoc(int signum);

/*----------------------TOKENS---------------------*/
int		ft_tokenization(t_minishell *shell);
t_token	*ft_new_token(char *t_value, t_token_type t_type);
int		ft_tokens_add_back(t_token **tokens, t_token *new);
int		ft_is_separator(char c);
int		ft_skip_quotes(char *line, size_t *i);
void	ft_clean_tokens(t_token **tokens);

/*----------------------PARSING--------------------*/
int		ft_parse(t_minishell *shell);
int		ft_check_syntax_errors(t_minishell *shell);
int		ft_init_cmd_args(t_minishell *shell);
int		ft_parse_redirections(t_minishell *shell);
int		ft_parse_output(t_minishell *shell, char *str, int n);
int		ft_parse_input(t_minishell *shell, char *str);
int		ft_parse_heredoc(t_minishell *shell, char *str);

/*-------------------PARSING-UTILS-----------------*/
char	**ft_delete_arg(t_minishell *shell, char *str);
void	ft_set_error(t_minishell *shell, char *str);
char	*ft_remove_quotes(char *delim);
void	ft_if_cleared_put_logo(t_minishell *shell, char *path);

/*---------------------EXPANSION-------------------*/
int		ft_expand_vars(t_minishell *shell);
char	*ft_checker(char *str1, char *str2);
char	*ft_handle_squotes(t_minishell *shell, char *str, int *j);
char	*ft_handle_normal_c(t_minishell *shell, char *str, int *j);
char	*ft_handle_dolar(t_minishell *shell, char *str, int *j, int d);
char	*ft_handle_dquotes(t_minishell *shell, char *str, int *j);
int		ft_remove_empty(t_minishell *shell, char *str);
int		ft_expand(t_minishell *shell, char *str, int i);
int		ft_quote_exists(char *str);

/*-----------------------EXEC----------------------*/
void	ft_execute(t_minishell *shell);
int		ft_is_builtin(t_minishell *shell, int *fd);
int		ft_pwd(t_minishell *shell, int *fd);
int		ft_echo(t_minishell *shell, int *fd);
int		ft_env(t_minishell *shell, int *fd);
int		ft_unset(t_minishell *shell);
int		ft_export(t_minishell *shell, int *fd);
int		ft_cd(t_minishell *shell);
int		ft_exit(t_minishell *shell);
int		ft_get_path(t_minishell *shell, char **path);
void	ft_child_exit(t_minishell *shell, int *status, char **path);
void	ft_close_redirections(t_minishell *shell);

/*--------------------EXEC-UTILS-------------------*/
char	*ft_extract_env_value(char **envp, char *var);
int		ft_copy_env(t_minishell *shell, char **new, int *i);
int		ft_check_key(char *str);
int		ft_is_dir(char **path);
int		ft_is_abs_or_rel(char *path);
int		ft_get_full_path(t_minishell *shell, char *s2, char **path, int *i);
void	ft_putstr_fd_new(int fd, char *str);
int		ft_is_piped(t_minishell *shell);
int		ft_strlen_env(char *env);
int		ft_get_n(char *env, char *arg);
void	ft_export_printer(t_minishell *shell, int *i, int tmp_fd);
char	**ft_import_env(t_minishell *shell, char *env);
int		ft_is_piped(t_minishell *shell);
int		ft_count_pipes(t_minishell *shell);

/*-----------------------ERROR---------------------*/
void	ft_print_error(t_minishell *shell, char *error, char *str, int status);
int		ft_print_syntax_err(t_minishell *shell, char *error, t_token *current);

/*---------------------CLEANING--------------------*/
int		ft_set_exit(t_minishell *shell, int status);
void	free_matrix(char **matrix);
void	ft_clean_all(t_minishell *shell, int exit_status, char *error);
void	ft_clean(t_minishell *shell);

#endif
