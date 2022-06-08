/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:56:15 by dwren             #+#    #+#             */
/*   Updated: 2022/01/19 16:42:42 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_programm
{
	char				*programm_path;
	char				**programm_argv;
	char				**programm_envp;
	struct s_programm	*next;
}t_programm;

void			open_fd_for_read(char *argv[], int *fd);
void			open_fd_for_write(int argc, char *argv[], int *fd);

int				found_in_envp_path(char *envp[]);
char			*take_path(char **path, char *prog_name);

void			wait_for_all_execve(t_programm *programms);
void			free_splited_argv(char **s);
int				free_arguments_for_execve(t_programm *programms);
t_programm		*create_arguments_for_execve(int argc,
					char **paths, char *argv[], char *envp[]);

void			do_one_prog(int one_pipe[2], char *path,
					char **prog, char *envp[]);

int				shell_ft_strncmp(const char *s1, const char *s2, size_t n);
int				shell_perror(const char *s);
void			shell_dup2(int fd_old, int fd_new, char *message_if_error);
void			shell_pipe(int one_pipe[2], char *message_if_error);
int				shell_fork(char *message_if_error);

#endif