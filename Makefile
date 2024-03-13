NAME = minishell
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lreadline
INCLUDES = i_include
LIBFT = l_libft

SRC_INIT = \
	main.c \
	ms_init/init_shell.c \
	ms_init/signals.c \
	ms_init/signals_heredoc.c \
	ms_init/init_logo.c

SRC_TOKENS = \
	ms_tokens/tokens.c \
	ms_tokens/tokens_list.c \
	ms_tokens/tokens_utils.c

SRC_PARSING = \
	ms_parsing/parse.c \
	ms_parsing/expand.c \
	ms_parsing/expand_utils.c \
	ms_parsing/expand_empty_dolar.c \
	ms_parsing/parse_syntax_check.c \
	ms_parsing/parse_utils.c \
	ms_parsing/parse_out_redirect.c \
	ms_parsing/parse_in_redirect.c \
	ms_parsing/parse_heredoc.c \
	ms_parsing/parse_init_heredocs.c

SRC_EXECUTE = \
	ms_execute/exec.c \
	ms_execute/exec_builtins.c \
	ms_execute/exec_cd.c \
	ms_execute/exec_echo.c \
	ms_execute/exec_env.c \
	ms_execute/exec_export.c \
	ms_execute/exec_pwd.c \
	ms_execute/exec_unset.c \
	ms_execute/exec_utils.c \
	ms_execute/exec_export_utils.c \
	ms_execute/exec_exit.c \
	ms_execute/exec_utils2.c \
	ms_execute/exec_get_path.c \
	ms_execute/exec_shlvl.c

SRC_ERROR = \
	ms_error/err_msg.c \
	ms_error/clean.c

SRCS = \
	$(SRC_INIT) \
	$(SRC_TOKENS) \
	$(SRC_PARSING) \
	$(SRC_EXECUTE) \
	$(SRC_ERROR)


all: $(NAME)
 
$(NAME): $(SRCS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@  $^ -I./$(INCLUDES) $(LFLAGS) -L./$(LIBFT) -lft

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
