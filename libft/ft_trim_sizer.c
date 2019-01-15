/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_sizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:30:01 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 14:50:50 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_trim_sizer(char const *s)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (ft_is_trim(s[i]) && s[i])
		i++;
	while (s[i])
	{
		size++;
		i++;
	}
	i--;
	while (ft_is_trim(s[i]) && size)
	{
		i--;
		size--;
	}
	return (size);
}
