/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:16:44 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 19:18:27 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*trim;

	if (s)
	{
		i = 0;
		j = 0;
		if (!(trim = (char *)malloc((ft_trim_sizer(s) + 1)
					* sizeof(char))))
			return (NULL);
		while (ft_is_trim(s[i]) && s[i])
			i++;
		while (j < ft_trim_sizer(s))
		{
			trim[j] = s[i];
			i++;
			j++;
		}
		trim[j] = '\0';
		return (trim);
	}
	return (NULL);
}
