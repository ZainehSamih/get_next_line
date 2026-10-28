/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalmoma <zaalmoma@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:12:42 by zaalmoma          #+#    #+#             */
/*   Updated: 2026/10/22 12:29:22 by zaalmoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*dsttmp;
	unsigned char	*srctmp;

	dsttmp = (unsigned char *) dst;
	srctmp = (unsigned char *) src;
	while (n > 0)
	{
		*dsttmp = *srctmp;
		dsttmp++;
		srctmp++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	flen;
	size_t	slen;
	size_t	comb;
	size_t	i;
	char	*str;

	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	comb = flen + slen;
	str = malloc(comb + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < comb)
	{
		if (i < flen)
			str[i] = s1[i];
		else
			str[i] = s2[i - flen];
		i++;
	}
	str[comb] = '\0';
	return (str);
}

char	*allocate(char *stash, int len)
{
	char	*save;

	save = malloc(len + 1);
	if (!save)
		return (NULL);
	ft_memcpy(save, stash, len);
	save[len] = '\0';
	return (save);
}

int	update_stash(char **stash, int len)
{
	int		remain;
	char	*save;

	remain = ft_strlen(*stash) - len;
	save = malloc(remain + 1);
	if (!save)
		return (0);
	ft_memcpy(save, *stash + len, remain);
	save[remain] = '\0';
	free(*stash);
	*stash = save;
	return (1);
}
