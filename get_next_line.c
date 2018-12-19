/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:22:02 by dtony             #+#    #+#             */
/*   Updated: 2018/12/19 20:03:22 by dtony            ###   ########.fr       */
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
	t_line	linus;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	if (line && fd > 0)
	{
		while ((linus.ret = read(fd, buf, BUFF_SIZE)))
		{
			linefiller(temp, buf, '\n');
			ft_strjoin(*line, 
}
