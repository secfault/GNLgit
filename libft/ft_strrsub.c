/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:19:14 by dtony             #+#    #+#             */
/*   Updated: 2018/12/19 19:20:33 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (s)
	{
		if (!(ret = (char *)malloc(len + 1)))
			return (NULL);
		ret[len] = '\0';
		ft_memrcpy(ret, s + start, len);
		return (ret);
	}
	return (NULL);
}
