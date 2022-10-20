/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:04:51 by sfarina           #+#    #+#             */
/*   Updated: 2022/08/17 15:35:07 by sfarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*united;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *) malloc (sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	united = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	free (s1);
	return (united);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

char	*ft_newb(char *buff)
{
	size_t	a;
	size_t	len;
	char	*newb;

	a = 0;
	len = 0;
	while (buff[a] != '\0' && buff[a] != '\n')
		a++;
	if (!buff[a])
	{
		free (buff);
		return (NULL);
	}
	newb = (char *) malloc(sizeof(char) * (ft_strlen(buff) - a + 1));
	if (!newb)
	{
		free (newb);
		return (NULL);
	}
	a++;
	while (buff[a] != '\0')
		newb[len++] = buff[a++];
	newb[len] = '\0';
	free (buff);
	return (newb);
}
