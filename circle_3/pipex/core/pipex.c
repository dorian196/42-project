/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:43:07 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/25 12:00:31 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	init_pipex(&pipex, argc, argv);
	ft_pid(&pipex, argc, argv, envp);
	ft_check_status(&pipex);
	free_error(&pipex, "", pipex.exit_code);
	return (0);
}
