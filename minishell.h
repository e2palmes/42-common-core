#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>

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
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	**env;
	int		exit_status;
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

#endif