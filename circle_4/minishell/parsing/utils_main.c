/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:25:41 by thobenel          #+#    #+#             */
/*   Updated: 2024/12/12 17:25:42 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_up(t_token **token, char **input)
{
	if (token && *token)
		ft_free_token(*token);
	if (input && *input)
		free(*input);
}

int	ft_handle_exit(char *input)
{
	if (ft_strcmp_parsing(input, "exit") == 0)
	{
		printf("Bye Bye !! 👋\n");
		free(input);
		return (0);
	}
	return (1);
}

void	ft_intro(void)
{
	ft_printf("\033[32m");
	ft_printf("\n  ███╗   ███╗██╗███╗   ██╗██╗\
	███████╗██╗  ██╗███████╗██╗     ██╗     \n");
	ft_printf("  ████╗ ████║██║████╗  ██║██║\
	██╔════╝██║  ██║██╔════╝██║     ██║\n");
	ft_printf("  ██╔████╔██║██║██╔██╗ ██║██║\
	███████╗███████║█████╗  ██║     ██║\n");
	ft_printf("  ██║╚██╔╝██║██║██║╚██╗██║██║\
	╚════██║██╔══██║██╔══╝  ██║     ██║\n");
	ft_printf("  ██║ ╚═╝ ██║██║██║ ╚████║██║\
	███████║██║  ██║███████╗███████╗███████╗\n");
	ft_printf("  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝\
	╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
	ft_printf("\033[0m\n");
	ft_printf("Bienvenue dans Minishell 🎉\n");
	ft_printf("Par Dpascal--Thobenel\n");
	ft_printf("Tapez 'exit' pour quitter.\n\n");
}
