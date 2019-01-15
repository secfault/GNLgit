/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:33:03 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 11:33:51 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	size_t			i;

	if (len == 0 || dest == src)
		return (dest);
	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
