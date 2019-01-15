/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:12:31 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 12:25:19 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ret;

	i = ft_strlen(str);
	ret = (char *)str;
	while (i >= 0)
	{
		if (ret[i] == (char)c)
			return (ret + i);
		i--;
	}
	return (NULL);
}
