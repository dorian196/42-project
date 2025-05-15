/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:48 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/21 13:46:58 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_timer(void)
{
	struct timeval	tv;
	long			sec;
	long			micro;
	long			milli;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec;
	micro = tv.tv_usec;
	milli = (sec * 1000) + (micro / 1000);
	return (milli);
}
