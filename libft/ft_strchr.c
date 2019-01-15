/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:38:21 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 12:12:02 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)str;
	while (ret[++i])
		if (ret[i] == (char)c)
			return (ret + i);
	if ((char)c == '\0' && ret[i] == '\0')
		return (ret + i);
	return (NULL);
}
