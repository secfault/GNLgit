/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:22:02 by dtony             #+#    #+#             */
/*   Updated: 2018/12/17 19:59:56 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	size_t	nbr;
	reader	linus;

	linus.fd = fd;
	linus.ret = read(linus.fd, linus.buff, BUFF_SIZE);
	while (linus.ret)
		ft_strendl(linus.buff);
	return (0);
}
