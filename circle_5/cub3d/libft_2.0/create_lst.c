/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:00:52 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:46:19 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	create_lst(t_gnl_list **list, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*heap_str;
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
		return ;
	buf[n] = '\0';
	heap_str = ft_strdup_v2(buf);
	if (!heap_str)
		return ;
	list_new(list, heap_str);
}
