/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:31:43 by dtony             #+#    #+#             */
/*   Updated: 2018/12/19 20:03:25 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include "libft/libft.h"

typedef static struct	s_line
{
	int					fd;
	int					ret;
	char				*temp;
	t_reader			*prev;
	t_reader			*next;
}						t_line;

#endif
