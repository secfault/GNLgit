/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:49:05 by dtony             #+#    #+#             */
/*   Updated: 2019/01/07 19:32:46 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*linefiller(char *buf, char c)
{
	char	*dest;

	dest = NULL;
	if (buf && c)
		dest = ft_strrsub(buf, ft_strchr(buf, c),
						  ft_strrlen(ft_strchr(buf, c)));
	return (dest);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stock;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !(line))
		return (-1);
	if (stock && ft_strchr(stock, '\n'))
	{
		*line = linefiller(stock, '\n');
		stock = ft_strdup(ft_strchr(stock, '\n'));
		ft_putstr(*line);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[BUFF_SIZE + 1] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strmcat(*line, linefiller(*line, buf, '\n'));
			ft_putstr(*line);
			free(stock);
			stock = ft_strdup(ft_strchr(buf, '\n');
			break;
		}
		else
		{
			*line = ft_strmcat(*line, buf);
			stock = (stock) ? ft_strmcat(stock, buf) : ft_strdup(buf);
		}
	}
	
}
