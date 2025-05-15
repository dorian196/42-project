/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:10 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/25 12:00:22 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	init_var(pipex);
	if (argc < 4)
	{
		ft_printf(2, "%s\n", ARGC_ERROR);
		exit(0);
	}
	pipex->infile = open(argv[1], O_RDONLY, 0644);
	if (pipex->infile < 0)
	{
		ft_printf(2, "bash: ");
		perror(argv[1]);
		pipex->infile = open("temp_null", O_RDONLY | O_CREAT | O_TRUNC, 0644);
		pipex->error = 1;
	}
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->outfile < 0)
	{
		ft_printf(2, "bash: ");
		perror(argv[argc - 1]);
		pipex->outfile = open("temp_null2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		pipex->error_outfile = 1;
	}
	if (pipe(pipex->pipefd) == -1)
		free_error(pipex, "Error : pipefd", 0);
}
