/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:57:01 by dtony             #+#    #+#             */
/*   Updated: 2018/12/20 18:02:07 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		if (!(ret = (char *)malloc(ft_strlen(s1) +
								   ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
		return (ret);
	}
	return (NULL);
}
