/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:24:03 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/04/25 18:25:14 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	f;
	char	*result;

	s = 0;
	f = ft_strlen(s1);
	if (f == 0)
	{
		result = (char *)malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	while (ft_strchr (set, s1[s]) != NULL && s < f)
		s++;
	while (ft_strchr (set, s1[f]) != NULL && s < f)
		f--;
	result = (char *)malloc(f - s + 2);
	if (!result)
		return (NULL);
	ft_strlcpy (result, &s1[s], (f - s + 2));
	return (result);
}
