/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:22:02 by dtony             #+#    #+#             */
/*   Updated: 2018/12/20 18:26:44 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*linefiller(char *dest, char *buf, char c)
{
	if (dest && buf && c)
		dest = ft_strrsub(buf, ft_strchr(buf, c),
						  ft_strrlen(ft_strchr(buf, c)));
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	static char	*temp;
	char		buf[BUFF_SIZE + 1];
	char		**lines;

	if (line && fd > 0)
	{
		i = 0;
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			temp = ft_strjoin_free(temp, buf);
			if (ft_strchr(buf, '\n'))
				break;
		}
		lines = ft_strsplit(lines, temp, '\n');
		*line = ft_strdup(lines[0]);
		free(temp);
		temp = ft_strchr(temp, '\n');
	}
	return (-1);
}
