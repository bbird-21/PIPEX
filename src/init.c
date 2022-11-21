/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/21 17:58:51 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
#include "tools.h"
#include "error.h"
#include "pipex.h"
#include "utils.h"
#include <stdlib.h>

void	init(int argc, char **argv, char **env,  t_data *data)
{
	if (argc < 5)
		exit_error(ERR_ARG);
	data->collect = NULL;
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.env = env;
	data->n_pipes = (argc - 4);
	data->pfd = malloc(sizeof(int) * (data->n_pipes * 2));
	data->fd[0] = -2;
	data->fd[1] = -2;
	check_path_env(data);
	check_file_permission(data);
	if (ft_strcmp(argv[1], "here_doc"))
		here_doc(data);
}
