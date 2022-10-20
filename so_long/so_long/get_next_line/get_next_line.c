/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:22:43 by sfarina           #+#    #+#             */
/*   Updated: 2022/08/17 16:24:46 by sfarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		len;
	char	*str;

	str = (char *) malloc ((sizeof(char) * BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	len = 1;
	while (len != 0 && ft_strchr(buff, '\n') == 0)
	{
	len = read(fd, str, BUFFER_SIZE);
		if (len == -1)
		{
			free (str);
			return (NULL);
		}
	str[len] = '\0';
	buff = ft_strjoin(buff, str);
	}
	free (str);
	return (buff);
}

char	*ft_def_line(char *buff)
{
	int		a;
	char	*new;

	a = 0;
	if (!buff[a])
		return (NULL);
	while (buff[a] != '\n' && buff[a] != '\0')
		a++;
	new = (char *) malloc (sizeof(char) * (a + 2));
	if (!new)
		return (NULL);
	a = 0;
	while (buff[a] && buff[a] != '\n')
	{
		new[a] = buff[a];
		a++;
	}
	if (buff[a] == '\n')
	{
		new[a] = buff[a];
		a++;
	}
	new[a] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	new = ft_def_line(buff);
	buff = ft_newb(buff);
	return (new);
}
