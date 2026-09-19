/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>


# define REDIR_QUOTED 1
# define REDIR_AMBIGUOUS 2

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_IN,

	TOKEN_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				flags;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	t_token			*words;
	char			**argv;
	t_token			*redirs;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	**env;
	int		exit_status;
	int		should_exit;
}	t_shell;

typedef struct s_expand
{
	char	*buffer;
	size_t	len;
	size_t	capacity;
	int		active;
	char	quote;
	t_token	*fields;
}	t_expand;

typedef struct s_pipeline
{
	int	input;
	int	pipefd[2];
}	t_pipeline;

char	**env_copy(char **envp);
void	env_free(char **env);
int		builtin_env(t_shell *shell);
t_token	*token_new(char *str, size_t len, t_token_type type);
void	token_add(t_token **tokens, t_token *new);
void	tokens_free(t_token *tokens);
int		lexer_space(char c);
int		lexer_operator(char c);
size_t	lexer_word_len(char *str);
int		lexer(char *line, t_token **tokens);
int		syntax_check(t_token *tokens);
// Parser
t_cmd	*command_new(void);
void	commands_free(t_cmd *commands);
t_token	*token_copy(t_token *source, t_token_type type);
int		parser(t_token *tokens, t_cmd **commands);
void	print_commands(t_cmd *commands);
// expansion
char		*env_strdup(const char *str);
const char	*env_value(char **env, const char *name, size_t len);
char		*expand_variable(t_shell *shell, const char *str, size_t *consumed);
int		expand_append(t_expand *exp, char c);
int		expand_flush(t_expand *exp);
int		expand_step(t_expand *exp, const char **str, t_shell *shell);
int		expand_word(const char *str, t_shell *shell, t_token **fields);
int		expand_words(t_cmd *commands, t_shell *shell);
int		expand_redirs(t_token *redirs, t_shell *shell);
int		prepare_commands(t_cmd *commands, t_shell *shell);
// execution d'une commande externe
int		exec_message(const char *name, const char *message, int status);
int		exec_error(const char *name, int error);
int		exec_search(t_cmd *command, t_shell *shell);
int		exec_external(t_cmd *command, t_shell *shell);
int		execute_commands(t_cmd *commands, t_shell *shell);
// Les builtins
int		write_string(int fd, const char *str);
int		builtin_echo(char **argv);
int		builtin_pwd(void);
int		run_builtin(t_cmd *command, t_shell *shell);
size_t	env_key_len(const char *entry);
int		env_index(char **env, const char *name, size_t len);
int		env_set(t_shell *shell, const char *entry);
char	**env_sorted(char **env);
int		export_list(t_shell *shell);
int		builtin_export(char **argv, t_shell *shell);
int		builtin_unset(char **argv, t_shell *shell);
char	**env_for_exec(char **env);
int		env_set_value(t_shell *shell, const char *name, const char *value);
int		builtin_cd(char **argv, t_shell *shell);
int		exit_number(const char *str, int *status);
int		builtin_exit(char **argv, t_shell *shell);

int		is_builtin(const char *name);
int		fd_redirect(int source, int target);
int		save_stdio(int saved[2]);
int		restore_stdio(int saved[2]);
int		has_heredoc(t_token *redirs);
int		apply_redirections(t_token *redirs);
int		execute_parent(t_cmd *command, t_shell *shell);

int		wait_child(pid_t pid);
void	pipeline_close(t_pipeline *pipeline);
int		pipeline_child(t_cmd *command, t_shell *shell,
			t_pipeline *pipeline);
int		pipeline_wait(t_cmd *commands, int failed);
int		execute_pipeline(t_cmd *commands, t_shell *shell);

#endif