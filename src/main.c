/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:47:51 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/18 19:16:51 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "utils.h"
#include "get.h"
#include "error.h"
#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

static void	pipex(t_data *data)
{
	int	i;
	int	pid;
	int	status;

	i = 2;
	if (pipe(data->pfd) == -1)
		exit_error(ERR_PIPE);
	if (pipe(data->pfd + 2) == -1)
		exit_error(ERR_PIPE);
	exe_firstbin(data);
	if (data->args.argc == 5)
		return (exe_lastbin(data));
	while (++i < data->args.argc - 2)
	{
		printf("test\n");
		check_bin_permission(data, i);
		pid = fork();
		if (pid < 0)
			exit_error(ERR_FORK);
		else if (pid == 0)
			exe_bin(data);
		freemem(data);
	}
	// exe_lastbin(data);
	// wait(&status);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init(argc, argv, env, &data);
	pipex(&data);

	// check_bin_permission(&data, 2);
	// exe_firstbin(&data);
	// freemem(&data);

	// check_bin_permission(&data, 3);
	// exe_lastbin(&data);
	// freemem(&data);

	// check_bin_permission(&data, 4);
	// exe_bin(&data);
	// freemem(&data);
	// close_fd(&data);


	return (21);
}
