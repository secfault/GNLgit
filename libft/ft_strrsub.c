/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:19:14 by dtony             #+#    #+#             */
/*   Updated: 2019/01/31 13:29:48 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrsub(const char *start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (start && len)
	{
		if (!(ret = (char *)malloc(len + 1)))
			return (NULL);
		ret[len + 1] = '\0';
		ft_memrcpy(ret, start, len);
	}
	return (ret);
}
