/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:24:33 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 19:11:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/* The open() system call requires these preprocessor directives  */
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>

/* Definition of boolean type  */
typedef enum e_bool
{
			FALSE,
			TRUE
}			t_bool;

/* Definition of ERROR_SIGNAL  */
typedef enum e_sig_err {
	ERR_OPEN,
	ERR_ARG,
	ERR_EXIST,
	ERR_EXE,
	ERR_FORK,
	ERR_PIPE,
	ERR_MEM,
	ERR_ENV,
	ERR_PATH,
	ERR__LENGHT
}	t_sig_err;

/* It required by exit_error in <main.c> to handle differents
   types of errors  */
typedef struct s_error
{
	int		sig_err;
	char	*sig_msg;
}			t_error;

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**env;
}			t_args;

typedef struct	s_collector
{
	void				*collect;
	struct s_collector	*next;
}				t_collector;

typedef struct s_data
{
	int		pfd[4];
	int		fd[2];
	char	**path;
	char	**bin_args;
	char	*bin_path;
	char	*bin;
	int		n_pipes;
	t_collector		*collect;
	t_args			args;
}			t_data;

#endif
