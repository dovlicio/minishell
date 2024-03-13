/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:05:04 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/19 23:55:19 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

# define ERROR_UNCLOSED_QUOTE    "quotes must be closed\n"
# define ERROR_INVALID_ARGUMENT  "this program takes no arguments\n"
# define ERROR_MALLOC_FAIL       "malloc failed\n"
# define ERROR_TOO_MANY_ARGS     "too many arguments\n"
# define ERROR_NO_SUCH_FILE      "No such file or directory\n"
# define ERROR_CMD_NOT_FOUND     "command not found\n"
# define ERROR_NOT_VALID_IDENT   "not a valid identifier\n"
# define ERROR_NUMERIC_REQUIRED  "numeric argument required\n"
# define ERROR_IS_DIR            "Is a directory\n"
# define ERROR_PERMISSION_DENIED "Permission denied\n"
# define ERROR_WRONG_SYNTAX      "syntax error near unexpected token `"
# define ERROR_CLOSING_FAILED    "Failed to close a file\n"
# define ERROR_FILE_OPEN_FAILED  "Failed to open a file\n"
# define ERROR_ENV_IMPORT_FAILED "minishell: Failed to import envp\n"
# define ERR_NH                   "HOME not set\n"
# define ERROR_HEREDOC_EOF_DELIM "warning: here-document delimited \
by end-of-file\n"

#endif
