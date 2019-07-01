/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:16:11 by dtony             #+#    #+#             */
/*   Updated: 2019/04/26 11:10:42 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int			checkstock(int fd, char **stock, char **line)
{
	int		i;
	char	*end;
	char	*tmp;

	i = 0;
	end = NULL;
	tmp = NULL;
	if (stock[fd] && ft_strchr(stock[fd], '\n'))
	{
		printf("checkstock \\n\n");
		if (stock[fd][0] == '\n')
		{
			printf("0 first\n");
			while (stock[fd][i] == '\n' && stock[fd][i])
				i++;
			if ((end = ft_strchr(stock[fd] + i, '\n')) != NULL)
				*line = ft_strsub(stock[fd], i, end - stock[fd] - i);
			tmp = ft_strdup(stock[fd] + i);
			free(stock[fd]);
			stock[fd] = NULL;
			if (  ft_strchr(tmp, '\n') && *(ft_strchr(tmp, '\n') + 1) != '\0'  )
				stock[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
			free(tmp);
			tmp = NULL;
			return (*line == NULL ? 0 : 1);
		}
		else
		{
			printf("normal\n");
			if ((end = ft_strchr(stock[fd], '\n')) != NULL)
				*line = ft_strsub(stock[fd], 0, end - stock[fd]);
			tmp = ft_strdup(stock[fd]);
			free(stock[fd]);
			stock[fd] = NULL;
			if ( ft_strchr(tmp, '\n') && *(ft_strchr(tmp, '\n') + 1) != '\0'  )
				stock[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
			free(tmp);
			tmp = NULL;
		}
		return (1);
	}
	// if (stock[fd][0])
	// {
	// 	
	// 	free(stock[fd]);
	// 	stock[fd] = NULL;
	// 	return (1);
	// }
	if (stock[fd])
	{
		*line = ft_strdup(stock[fd]);
		free(stock[fd]);
		stock[fd] = NULL;
		return (1);
	}
	return (0);
}

// static int			parse(int fd, char *str, char *stock char **line)
// {
	
// }

static int			readline(char **stock, char **line, char *buf, int fd)
{
	char	*end;
	char	*new;

printf("____________READLINE____________\n");
	if (buf[0] == '\n')
	{
		printf("start 0\n");
		end = ft_strchr(buf + 1, '\n');
		printf("end: '%s'\n", end);
		if(stock[fd])
		{
			printf("stockforline: %s\n", stock[fd]);
			*line = ft_strdup(stock[fd]);
			free(stock[fd]);
			stock[fd] = NULL;
		}
		else if (end != NULL)
		{
			printf("nostock\n");
			*line = ft_strsub(buf, 1, end - buf - 1);
		}
		if (end != NULL && end[1] != '\0')
		{
			// verifier ret
			stock[fd] = ft_strdup(end + 1);
			printf("stockbufend: '%s'\n", stock[fd]);
		}
		else if (ft_strlen(buf) < BUFF_SIZE)
		{
			printf("lastbuff in stock\n");
			stock[fd] = ft_strdup(buf);
		}
		// gerer buf restant
	}
	else
	{
		printf("start normal\n");
		end = ft_strchr(buf, '\n');
		if (stock[fd])
		{
			new = ft_strsub(buf, 0, end - buf);
			*line = ft_strfjoin(stock[fd], new);
			free(new);
			new = NULL;
		}
		else
			*line = ft_strsub(buf, 0, end - buf);
		if ((end + 1) != '\0')
		{
			stock[fd] = ft_strdup(end + 1);
			printf("stockbuf: '%s'\n", stock[fd]);
		}
	}
	printf("_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_\n");
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stock[999];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !(line) || read(fd, buf, 0) < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		printf("ret = '%i'  buf: '%s'\nbuf length = %zu\n", ret, buf, ft_strlen(buf));
		// verifier ret
		if (stock[fd] && ft_strchr(stock[fd], '\n'))
			if (checkstock(fd, stock, line))
				return(1);
		if (ft_strchr(buf, '\n') &&
				readline(stock, line, buf, fd))
		{
			printf("readline\n");
			// if (ret < BUFF_SIZE)
			// 	stock[fd] = ft_strfjoin(stock[fd], buf);
			return (1);
		}
		else
		{
			stock[fd] = ft_strfjoin(stock[fd], buf);
			printf("fillstock: '%s'\n", stock[fd]);
		}
		// if	(ret < BUFF_SIZE)
		// {
		// 	printf("laststock: '%s'\n", stock[fd]);
		// 	checkstock(fd, stock, line);
		// 	return (1);
		// }
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	printf("out\n");
	printf("last check\n");
	return (checkstock(fd, stock, line) ? 1 : 0);
	printf("end\n");
	return (0);
}
