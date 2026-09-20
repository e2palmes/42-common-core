*This project has been created as part of the 42 curriculum by ediba-de, bherdenb.*

# Minishell

## Description

Minishell is my own small shell, written in C for 42. The goal is to understand what happens between typing a command in a terminal and seeing its result: reading the input, handling quotes and variables, creating processes, and connecting them with pipes.

I use Bash as a reference for the behavior required by the subject. This version focuses on the mandatory part.

It includes:

- A prompt and command history using Readline.
- Commands found through `PATH`, or given with a relative or absolute path.
- Single and double quotes, environment variables, and `$?`.
- Pipes (`|`) and redirections (`<`, `>`, `>>`, `<<`).
- The builtins `echo` (with `-n`), `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- Handling of `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`.

The bonus features (`&&`, `||`, parentheses, and wildcard expansion) are not included.

## Instructions

### Build

You need `cc`, Make, and the Readline development library. On Debian or Ubuntu:

```sh
sudo apt update
sudo apt install build-essential libreadline-dev
```

Then, from the project folder:

```sh
make
./minishell
```

The code is compiled with `-Wall -Wextra -Werror`.

To clean the project:

```sh
make clean    # Remove object files
make fclean   # Also remove the executable
make re       # Rebuild everything
```

### Try it

Once Minishell is running, you can enter commands like these:

```sh
echo "hello"
export MESSAGE=bonjour
echo "$MESSAGE"
echo '$MESSAGE'
ls -l | wc -l
```

To try redirections, the following commands create or overwrite `example.txt`:

```sh
echo first > example.txt
echo second >> example.txt
cat < example.txt
```

For a heredoc, type the delimiter on its own line to finish:

```sh
cat << END
hello from a heredoc
END
```

Use `echo $?` to check the last command's exit status. Type `exit`, or press `Ctrl-D` on an empty prompt, to leave the shell.

## How the code is organized

The headers are in `includes/`, and the source files are in `src/`.

| Folder in `src/` | What it handles                            |
| ---------------- | ------------------------------------------ |
| `input/`         | Reading a line and displaying the prompt   |
| `lexer/`         | Splitting the input into tokens            |
| `parser/`        | Checking syntax and building commands      |
| `expansion/`     | Expanding variables and handling quotes    |
| `builtins/`      | The shell's builtin commands               |
| `env/`           | Storing and updating environment variables |
| `execution/`     | Running commands, pipes, and redirections  |
| `heredoc/`       | Reading heredoc input                      |
| `signals/`       | Handling signals                           |
| `utils/`         | Helpers shared by several files            |

A builtin like `cd` runs in the parent when it is used on its own, so the directory change stays in effect. In a pipeline, commands run in children. The shell waits for them and keeps the exit status of the last command.

There is only one global variable, `g_signal`, which stores the received signal number.

## Resources

- The 42 Minishell subject, version 10.0.
- [Bash manual](https://www.gnu.org/software/bash/manual/bash.html) for reference behavior.
- [Readline documentation](https://www.gnu.org/software/readline/) for input and history.
- [Linux manual pages](https://man7.org/linux/man-pages/), especially `fork`, `execve`, `pipe`, `dup2`, `waitpid`, and `signal`.
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html) for the Makefile.

AI was used mainly to help with testing, debugging and explanations.
