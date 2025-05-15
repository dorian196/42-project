/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:58:26 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/25 11:59:33 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_var(t_pipex *pipex)
{
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->pipefd[0] = 0;
	pipex->pipefd[1] = 0;
	pipex->len = 0;
	pipex->pid = 0;
	pipex->i = 0;
	pipex->stdin_fd = 0;
	pipex->status = 0;
	pipex->exit_code = 0;
	pipex->error = 0;
	pipex->error_outfile = 0;
	pipex->cmd = NULL;
	pipex->paths = NULL;
	pipex->path = NULL;
	pipex->paths_cmd = NULL;
	pipex->path_cmd = NULL;
}
