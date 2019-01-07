/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:49:05 by dtony             #+#    #+#             */
/*   Updated: 2019/01/07 16:40:00 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*linefiller(char *dest, char *buf, char c)
{
	if (dest && buf && c)
		dest = ft_strrsub(buf, ft_strchr(buf, c),
						  ft_strrlen(ft_strchr(buf, c)));
	return (dest);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stock;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !(line))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ft_strchr(buf, '\n'))
			*line = linefiller(*line, buf, '\n');
	}
	if (ft_strchr(stock, '\n'))
	{
		*line = ft_strmcat(*line, stock, '\n');
		stock = ft_strchr(stock, '\n');
	}
