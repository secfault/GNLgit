/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:31:43 by dtony             #+#    #+#             */
/*   Updated: 2019/01/24 14:54:53 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

# define BUFF_SIZE 2

typedef struct		s_line
{
	int				fd;
	int				ret;
	char			*stock;
	struct s_line	*next;
}					t_line;

int		get_next_line(const int fd, char **line);

#endif
