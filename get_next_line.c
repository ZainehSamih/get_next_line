/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalmoma <zaalmoma@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:41:17 by zaalmoma          #+#    #+#             */
/*   Updated: 2026/10/24 11:29:27 by zaalmoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	has_newline(char *str)
{
	int	s;

	s = 0;
	while (str[s])
	{
		if (str[s] == '\n')
			return (1);
		s++;
	}
	return (0);
}

static int	read_to_stash(int fd, char **stash)
{
	char	*buffer;
	int		bytes;
	char	*new_stash;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = 1;
	while (!has_newline(*stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		if (!new_stash)
			return (free(buffer), -1);
		free(*stash);
		*stash = new_stash;
	}
	free(buffer);
	if (bytes <= 0)
		return (bytes);
	return (1);
}

static int	line_len(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		return (i + 1);
	return (i);
}

static int	result_check(int result, char *stash)
{
	if (result == -1)
		return (1);
	if (result == 0 && stash[0] == '\0')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*save;
	int			len;
	static char	*stash;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	result = read_to_stash(fd, &stash);
	if (result_check(result, stash))
		return (NULL);
	len = line_len(stash);
	save = allocate(stash, len);
	if (!save || !update_stash(&stash, len))
		return (free(save), NULL);
	return (save);
}
