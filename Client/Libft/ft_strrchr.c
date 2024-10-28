/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharfao <jcharfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 07:04:56 by jcharfao          #+#    #+#             */
/*   Updated: 2024/02/22 15:42:13 by jcharfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	p;

	p = c;
	i = ft_strlen(s);
	if (p == 0)
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == p)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
