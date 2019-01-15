/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:41:07 by dtony             #+#    #+#             */
/*   Updated: 2018/12/19 19:52:47 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, int bufsize)
{
	char	*cpy;
	char	*ret;

	if (ptr)
	{
		cpy = ft_strdup(ptr);
		free(ptr);
		if (!(ret = (char *)malloc(ft_strlen(cpy) + bufsize + 1)))
			return (NULL);
		ft_strcpy(ret, cpy);
		free(cpy);
	}
	return (NULL);
}
