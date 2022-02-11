/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:17:21 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/11 19:17:03 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
}

int	ft_indexof(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_line_if_read(char *buf, char **res)
{
	int		n_ind;
	char	*tmp;
	int		len;

	if (!buf)
		return (0);
	len = ft_strlen((char *)buf);
	n_ind = ft_indexof(buf, '\n');
	if (n_ind == -1)
	{
		*res = ft_strjoin(*res, buf);
		ft_memset(buf, '\0', len);
	}
	else
	{
		tmp = ft_substr(buf, 0, n_ind + 1);
		*res = ft_strjoin(*res, tmp);
		ft_free(tmp);
		tmp = ft_substr(buf, n_ind + 1, len - n_ind);
		ft_memcpy(buf, tmp, ft_strlen(tmp) + 1);
		ft_free(tmp);
		return (1);
	}
	return (0);
}

int	get_line_from_buf(char **buf, char s[], char **res, int len)
{
	int		ret;
	int		n_ind;
	char	*tmp;

	ret = 0;
	n_ind = ft_indexof(*buf, '\n');
	if (n_ind == -1)
		*res = ft_strjoin(*res, *buf);
	else
	{
		tmp = ft_substr(*buf, 0, n_ind + 1);
		*res = ft_strjoin(*res, tmp);
		ft_free(tmp);
		tmp = ft_substr(*buf, n_ind + 1, len - n_ind);
		ft_memcpy(s, tmp, ft_strlen(tmp) + 1);
		ft_free(tmp);
		ret = 1;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	s[100][BUFFER_SIZE];
	char		*buf;
	int			len;
	char		*res;

	res = NULL;
	if (fd > 100 || fd < 0)
		return (res);
	if (get_line_if_read(s[fd], &res) == 1)
		return (res);
	buf = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = '\0';
		if (get_line_from_buf(&buf, s[fd], &res, len) == 1)
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	ft_free(buf);
	if (len == -1)
		res = NULL;
	return (res);
}
