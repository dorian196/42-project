/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:56:06 by dpascal           #+#    #+#             */
/*   Updated: 2024/05/21 23:46:00 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_first_line(char *save)
{
	char	*s;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_after_line(char *save)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		bytes;
	char	*temp;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = save;
		save = ft_strjoin(temp, buff);
		free(temp);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_first_line(save[fd]);
	save[fd] = ft_after_line(save[fd]);
	return (line);
}
/*
int main(int argc, char **argv)
{
    int fd;
    char *line;
	int i;

    if (argc < 2)
        return (0);
	i = 0;
    while (i < argc)
    {
        fd = open("t.txt", O_RDONLY);
        if (fd == -1)
        	return (0);
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
		i++;
        close(fd);
    }
    return 0;
}*/
