/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 10:51:28 by dtony             #+#    #+#             */
/*   Updated: 2019/08/18 10:51:28 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*n_parse(char *str, int n)
{
    int	i;

		i = 0;
        if (!str)
            return (NULL);
		while (str[i] && str[i] == n)
			i++;
		if (str[i] == '\0')
			return (NULL);
		return (str + i);
}

static int			checkstock(int fd, char **stock, char **line)
{
	char	*end;
	char	*tmp;

	end = NULL;
	tmp = NULL;
    if (stock[fd])
    {
        if ((end = ft_strchr(stock[fd], '\n')) != NULL)
            *line = ft_strsub(stock[fd], 0, end - stock[fd]);
        tmp = n_parse(ft_strchr(stock[fd], '\n'), '\n');
        free(stock[fd]);
        stock[fd] = NULL;
        if (tmp && tmp[0])
        {
            stock[fd] = ft_strdup(tmp);
            free(tmp);
            tmp = NULL;
        }
    }
    return (*line ? 1 : 0);
}

static int			readline(char **stock, char **line, char *buf, int fd)
{
    int		i;
	char	*end;
	char	*new;

	i = 0;
	new = NULL;
    if (buf[0] == '\n')
    {
        if (stock[fd])
        {
            *line = ft_strdup(stock[fd]);
            free(stock[fd]);
            stock[fd] = NULL;
        }
        while (buf[i] == '\n' && buf[i])
			i++;
        end = ft_strchr(buf + i, '\n');
        if (end && !(*line))
            *line = ft_strsub(buf, i, end - buf - i);
        else if (buf[i])
            stock[fd] = ft_strdup(buf + i);
    }
    else
    {
        end = ft_strchr(buf, '\n');
		if (stock[fd])
		{
			new = ft_strsub(buf, 0, end - buf);
			*line = ft_strfjoin(stock[fd], new);
			free(new);
			new = NULL;
            stock[fd] = NULL;
		}
		else
			*line = ft_strsub(buf, 0, end - buf);
        if (n_parse(end, '\n'))
            stock[fd] = ft_strdup(n_parse(end, '\n'));
    }
    return (*line ? 1 : 0);
}

int					get_next_line(const int fd, char **line)
{
    int			ret;
	static char	*stock[_SC_OPEN_MAX];
	char		buf[BUFF_SIZE + 1];

    if (fd < 0 || !(line) || read(fd, buf, 0) < 0)
		return (-1);
    ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
        buf[ret] = '\0';
        if ((stock[fd] && ft_strchr(stock[fd], '\n')) && 
            (checkstock(fd, stock, line)))
                return (1);
        else if ((ft_strchr(buf, '\n')) && 
            (readline(stock, line, buf, fd)))
                return (1);
        else
            stock[fd] = ft_strfjoin(stock[fd], buf);
        ft_bzero(buf, BUFF_SIZE + 1);
    }
    if (stock[fd] && stock[fd][0])
    {
        *line = ft_strdup(stock[fd]);
        free(stock[fd]);
        stock[fd] = NULL;
        return (1);
    }
    if (stock[fd])
    {
        free(stock[fd]);
        stock[fd] = NULL;
    }
    return (0);
}