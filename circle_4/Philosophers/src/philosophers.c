/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:54:02 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/21 15:16:13 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_data	data_philo;
	t_philo	philo;

	if ((ac == 6 || ac == 5))
	{
		if (check_arg(av) != 0)
			return (0);
		init_var(&data_philo, &philo);
		if (init_data(av, &data_philo) != 0)
			return (1);
		if (ft_process(&data_philo) != 0)
			printf("Error in process\n");
		ft_free(&data_philo);
	}
	else if (ac != 6)
		printf("philo: Incorrect number of arguments\n");
	return (0);
}
