/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpideci <42kocaeli.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:10:10 by hpideci           #+#    #+#             */
/*   Updated: 2023/01/07 20:12:31 by hpideci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (!ft_strchr(s, (char)c))
		return (0);
	while (*s)
		s++;
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
