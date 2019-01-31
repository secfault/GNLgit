/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:04:34 by dtony             #+#    #+#             */
/*   Updated: 2019/01/31 16:59:28 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	while (len)
	{
		destcpy[len - 1] = srccpy[len - 1];
		len--;
	}
	destcpy[len] = srccpy[len];
	return (destcpy);
}
