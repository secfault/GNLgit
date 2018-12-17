/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:31:43 by dtony             #+#    #+#             */
/*   Updated: 2018/12/17 20:48:19 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>

typedef struct		reader
{
	int				fd;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	struct reader	*next;
}					reader;

#endif
