/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:17:37 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/11 19:05:59 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memset(void *s1, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)(s1);
	i = 0;
	while (i < n && *s)
	{
		*(int *)(s) = c;
		i++;
		s++;
	}
	return (s - n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = -1;
	while ((size_t)++i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	}
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_strlen(s) < start)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		while (i < (int)len && s[start])
			res[i++] = s[start++];
		res[i] = '\0';
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		i;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l2 == 0)
		return (s1);
	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < l1)
		res[i] = s1[i];
	i--;
	while (++i < l1 + l2)
		res[i] = s2[i - l1];
	if (s1)
		free(s1);
	res[i] = '\0';
	return (res);
}
