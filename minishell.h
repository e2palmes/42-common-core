#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>

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
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	t_token			*words;
	t_token			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	**env;
	int		exit_status;
}	t_shell;

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

#endif