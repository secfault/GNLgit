/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:16:11 by dtony             #+#    #+#             */
/*   Updated: 2019/01/31 20:16:11 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			checkstock(int fd, char **stock, char **line)
{
	char	*start;
	char	*tmp;

	tmp = NULL;
	if (stock[fd] && ft_strchr(stock[fd], '\n'))
	{
		start = ft_strchr(stock[fd], '\n');
		*line = ft_strsub(stock[fd], 0, start - stock[fd]);
		tmp = ft_strdup(stock[fd]);
		free(stock[fd]);
		stock[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
		return (1);
	}
	else if (stock[fd] && stock[fd][0])
	{
		*line = ft_strdup(stock[fd]);
		free(stock[fd]);
		return (1);
	}
	return (0);
}

static int			readline(char **stock, char **line, char *buf, int fd)
{
	char	*start;

	if (buf[0] == '\n')
		stock[fd] = ft_strdup(ft_strchr(buf, '\n') + 1);
	else
	{
		start = ft_strchr(buf, '\n');
		*line = ft_strsub(buf, 0, start - buf);
		stock[fd] = ft_strdup(ft_strchr(buf, '\n') + 1);
		return (1);
	}
	return (0);
	
}

int					get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stock[999];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !(line))
		return (-1);
	if (checkstock(fd, stock, line))
		return (1);
	ft_bzero(buf, ft_strlen(buf));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') &&
				readline(stock, line, buf, fd))
			return (1);
		else
			stock[fd] = ft_strjoin(stock[fd], buf);
		ft_bzero(buf, ft_strlen(buf));
	}
	if (checkstock(fd, stock, line))
		return (stock[fd] != NULL ? 1 : 0);
	if (stock[fd][1] != '\0')
		*line = ft_strdup(stock[fd]);
	return (0);
}
