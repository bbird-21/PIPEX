/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:47:36 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/12 12:52:19 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

#include "tools.h"

void	check_file_permission(int argc, char **argv, char **env, t_data *data);
void	check_bin_permission(int argc, char **argv, char **env, t_data *data, int index);
void	parse_args(int argc);
void	exit_error(int sig_err);

#endif